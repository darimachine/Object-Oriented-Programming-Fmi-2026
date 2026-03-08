#include  <iostream>
#include  <fstream>
using namespace std;

struct  Matrix
{
    int rows = 0, cols = 0;
    int **data = nullptr;

    int** createMatrix(int r, int c)
    {
        rows = r, cols = c;
        data = new int*[rows];

        for (int i =0; i <rows; i++)
        {
            data[i] = new int[cols];
        }
        return  data;
    }

    void deleteMatrix()
    {
        for (int i =0; i <rows; i++)
        {
            delete[] data[i];
        }
        delete [] data;
        data = nullptr;
    }

    void allocateMatrix(const char* fileName, int &rows, int &cols)
    {
        ifstream read(fileName);

        if (!read.is_open())
            return;

        char currSymb;
        int currCols = 1;
        rows = 1;
        cols = 0;
        while (read.get(currSymb))
        {
            if (currSymb == ',')
            {
                currCols++;

            }
            else if (currSymb =='|')
            {
                rows++;
                if (cols == 0)
                    cols = currCols;
                currCols = 1;
            }
        }
        if (cols == 0)
            cols = currCols;
        read.close();
    }

    void fillMatrix(const char* fileName, int**matrix, int rows, int cols)
    {
        ifstream read(fileName);

        if (!read.is_open())
            return;

        char separator;
        for (int i =0; i <rows; i++)
        {
            for (int j= 0; j<cols; j++)
            {
                read>>matrix[i][j];
                if (j< cols - 1)
                    read>>separator;
            }
            read>>separator;
        }
        read.close();
    }

    Matrix readMatrix(const char* fileName)
    {
        Matrix currMatrix;
        currMatrix.allocateMatrix(fileName, currMatrix.rows, currMatrix.cols);
        currMatrix.createMatrix(currMatrix.rows, currMatrix.cols);
        currMatrix.fillMatrix(fileName, currMatrix.data, currMatrix.rows, currMatrix.cols);

        return  currMatrix;
    }
    void multiply(const char* firstFIle, const char* secondFile, const char* resultFile)
    {
        Matrix temp;
        Matrix first = temp.readMatrix(firstFIle);
        Matrix second = temp.readMatrix(secondFile);

        if (first.cols != second.rows)
        {
            println("The matrixes could not be multiplied");
            first.deleteMatrix();
            second.deleteMatrix();
            return;
        }

        Matrix result;
        result.createMatrix(first.rows, second.cols);
        for (int i =0; i<first.rows; i++)
        {
            for (int j =0; j <second.cols; j++)
            {
                result.data[i][j] = 0;
                for (int k =0; k<first.cols; k++)
                {
                    result.data[i][j] += first.data[i][k] * second.data[k][j];
                }
            }
        }

        ofstream write(resultFile);
        for (int i =0; i <result.rows; i++)
        {
            for (int j =0; j<result.cols; j++)
            {
                write<<result.data[i][j];
                if (j < result.cols - 1)
                    write<<',';
            }
            if (i < result.rows - 1)
                write<<'|';
        }
        write.close();
        first.deleteMatrix();
        second.deleteMatrix();
        result.deleteMatrix();
        temp.deleteMatrix();
    }
};
int main()
{
    Matrix helper;
    helper.multiply("matrix1.txt", "matrix2.txt", "result.txt");
    return 0;
}