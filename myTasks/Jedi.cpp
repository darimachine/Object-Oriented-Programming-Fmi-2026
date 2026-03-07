#include <iostream>
#include  <cstring>
#include  <print>
#include <fstream>
using namespace std;

const int MAX_LEN_NAME = 51;
const int MIN_AGE = 0;
const int MIN_POWER  = 0;
const int MAX_JEDIES = 100;
enum class LightSaber_Color
{
    RED,
    YELLOW,
    GREEN,
    BLUE,
    PURPLE
};

enum class LightSaber_Type
{
    SINGLEBLADED,
    DOUBLE_BLADED,
    CROSSGUARD
};

struct  LightSaber
{
    LightSaber_Color color;
    LightSaber_Type type;
};
struct Jedi
{
    char name[MAX_LEN_NAME] ;
    int age;
    int power;
    LightSaber light_saber;

    Jedi(): age(0), power(0)
    {

        char *InitialName = "Unknown";
        strcpy(name, InitialName);
        light_saber.color = LightSaber_Color::RED;
        light_saber.type = LightSaber_Type::SINGLEBLADED;
    }

    Jedi(const char *name, int age, int power, const LightSaber& saber)
    {
        setName(name);
        setAge(age);
        setPower(power);
        light_saber = saber;
    }
    Jedi(const char *name, int age, int power, LightSaber_Color color_, LightSaber_Type type_)
    {
        setName(name);
        setAge(age);
        setPower(power);
        light_saber.color = color_;
        light_saber.type = type_
        ;
    }
    void setName(const char* name)
    {
        if (!name)
         return;

        strcpy(this->name, name);
    }

    void setAge(int age)
    {
        if (age < MIN_AGE)
        {
            this->age = 0;
            return;
        }
        this->age = age;
    }

    void setPower(int power)
    {
        if (power < MIN_POWER)
        {
            this->power = 0;
            return;
        }
        this->power = power;
    }

};

class JediCollection
{
    private:
        Jedi myJedies[MAX_JEDIES];
        int currJedicount;
    public:
    JediCollection(): currJedicount(0)
    {}

    JediCollection(int count): currJedicount(count)
    {}

    void AddJedi(const Jedi& currJedi)
    {
        if (currJedicount < MAX_JEDIES)
        {
            myJedies[currJedicount] = currJedi;
            currJedicount++;
        }
        else
        {
            cout<<"A new jedi can not be added to the collection. The team is already full!";
        }
    }

    void printMyJediesInfo() const
    {
        cout<<"Current jedi's team: "<<'\n';
        for (int i = 0; i <currJedicount; i++)
        {
            cout<<"Name: "<<myJedies[i].name<<" age: "<<myJedies[i].age<<" power: "<<myJedies[i].power<<" lightsaber color: "<<getColorName(myJedies[i].light_saber.color)<<" and type: "<<getTypeName(myJedies[i].light_saber.type)<<'\n';

        }
    }
    const char* getColorName(LightSaber_Color color) const
    {
        switch (color)
        {
            case LightSaber_Color::RED:
                return "Red";
            case LightSaber_Color::BLUE:
                return  "Blue";
            case LightSaber_Color::GREEN:
                return "Green";
            case LightSaber_Color::PURPLE:
                return "Purple";
            case LightSaber_Color::YELLOW:
                return  "Yellow";
            default: return  "Unknown";
        }
    }

    const char* getTypeName(LightSaber_Type type) const
    {
        switch (type)
        {
            case LightSaber_Type::SINGLEBLADED:
                return "singleBladed";
            case LightSaber_Type::CROSSGUARD:
                return  "crossGuard";
            case LightSaber_Type::DOUBLE_BLADED:
                return  "double-bladed";
            default: return  "unknown";
        }
    }

    void removeJedi(const char *name)
    {
        if (!name)
            return;

        bool isFound = false;
        int jediIdx = 0;
        for (int i = 0; i<currJedicount; i++)
        {
            if (strcmp(myJedies[i].name, name ) == 0)
            {
                isFound = true;
                jediIdx = i;
                break;

            }
        }

        if (!isFound)
        {
            cout<<"This jade: "<<name<<" is not found! The team remains the same."<<'\n';
            return;
        }

        for (int i = jediIdx; i <currJedicount - 1; i++)
        {
          myJedies[i] = myJedies[i + 1];
        }

        cout<<"The jedi: "<<name<<" is successfully removed from the team"<<'\n';
        currJedicount--;
        cout<<"The teamCount is: "<<currJedicount<<'\n';

    }

    int getTeamCount() const
    {
        return currJedicount;
    }

    Jedi& getJediAt(int i)
    {
        return  myJedies[i];
    }
};

class  JediData
{
    private:
     void swapJedies(Jedi &first, Jedi &second)
     {
         Jedi temp;
         temp = first;
         first = second;
         second = temp;
     }
public:
    void sortAgeJedies(JediCollection &collection)
    {
        int currTeamCount = collection.getTeamCount();
        for (int i =0; i<currTeamCount - 1; i++)
        {
            for (int j = 0; j < currTeamCount - i - 1; j++)
            {
                Jedi &first = collection.getJediAt(j);
                Jedi &second = collection.getJediAt(j + 1);
                if (first.age > second.age)
                    swapJedies(first, second);
            }
        }
    }

    void sortByPower(JediCollection &collection)
    {
        int currTeamCount = collection.getTeamCount();

        for (int i = 0; i < currTeamCount - 1; i++)
        {
            for (int j = 0; j < currTeamCount - i - 1; j++)
            {
                Jedi &first = collection.getJediAt(j);
                Jedi &second = collection.getJediAt(j + 1);

                if (first.power > second.power)
                    swapJedies(first, second);
            }
        }
    }

    LightSaber_Color mostPopularSaberColor(JediCollection &collection)
    {
        int colorCounters[5] ={0};

        int teamCount = collection.getTeamCount();

        for(int i= 0; i <teamCount; i++)
        {
            int colorIdx = (int)collection.getJediAt(i).light_saber.color;
            colorCounters[colorIdx]++;
        }

        int mostRecentColorCount = colorCounters[0];
        int mostRecentColorIdx = 0;

        for (int i = 1; i< 5; i++)
        {
            if (mostRecentColorCount < colorCounters[i])
            {
                mostRecentColorCount = colorCounters[i];
                mostRecentColorIdx = i;
            }
        }
        return (LightSaber_Color)mostRecentColorIdx;
    }

    LightSaber_Type mostPoplarSaberType(JediCollection &collection)
    {
        int saberTypes[3] = {0};
        int TeamCount = collection.getTeamCount();

        for (int i =0; i <TeamCount; i++)
        {
            int typeIdx = (int)collection.getJediAt(i).light_saber.type;
            saberTypes[typeIdx] ++;
        }

        int mostPopularType = saberTypes[0];
        int mostPopularIdx = 0;

        for (int i =0; i <3 ; i++)
        {
            if (mostPopularType < saberTypes[i])
            {
                mostPopularType = saberTypes[i];
                mostPopularIdx = i;
            }
        }
        return  (LightSaber_Type)mostPopularIdx;
    }
};

class JedilO
{
    public:
        void saveToTxt(JediCollection &myCollection, const char* fileName)
        {
            ofstream write(fileName);

            if (!write.is_open())
            {
                cout<<"The file was not open successfully opened";
                return;
            }

            int countJedies = myCollection.getTeamCount();
            write<<countJedies<<'\n';
            for (int i = 0; i<countJedies; i++)
            {
                const Jedi &currJedi = myCollection.getJediAt(i);
                write<<currJedi.name<<'\n';
                write<<currJedi.age<<'\n';
                write<<currJedi.power<<'\n';
                write<<(int)currJedi.light_saber.color<<'\n';
                write<<(int)currJedi.light_saber.type<<'\n';
            }
            write.close();
        }
        JediCollection readFromTxt(const JediCollection &collection, const char* fileName)const
        {
            ifstream read(fileName);
            JediCollection NewTeam;
            if (!read.is_open())
            {
                cout<<"The file was not opened successfully"<<'\n';
                return NewTeam;
            }
            int count;
            read>>count;

            for (int i =0; i<count; i++)
            {
                char JediName[MAX_LEN_NAME];
                int age, power, type, color;
                read>>JediName;
                read>>age;
                read>>power;
                read>>color;
                read>>type;

                Jedi temp(JediName, age, power, (LightSaber_Color)color, (LightSaber_Type)type);
                NewTeam.AddJedi(temp);
            }
            read.close();
            return NewTeam;
        }

    void saveToBinary(JediCollection &myCollection, const char * fileName)
        {
            ofstream out(fileName, ios::binary);
            if (!out.is_open())
                return;;

            int count =myCollection.getTeamCount();
            out.write((const char*)&count, sizeof(int));

            for (int i =0; i<count; i++)
            {
                const Jedi& currJedi = myCollection.getJediAt(i);
                out.write((const char*)& currJedi, sizeof(Jedi));
            }
            out.close();
        }
    JediCollection readFromBinary(const char* fileName)
        {
            JediCollection tempCollection;
            ifstream in(fileName, ios::binary);

            if (!in.is_open())
                return tempCollection;

            int count;
            in.read((char*)&count, sizeof(int));

            for (int i =0; i <count; i++)
            {
                Jedi tempJedi;
                in.read((char*)&tempJedi, sizeof(Jedi));
                tempCollection.AddJedi(tempJedi);
            }
            in.close();
            return  tempCollection;
        }
};
int main()
{
    LightSaber yodaSaber;
    yodaSaber.color = LightSaber_Color::RED;
    yodaSaber.type = LightSaber_Type::DOUBLE_BLADED;
    Jedi yoda("yoda", 50, 1500, yodaSaber);
    Jedi vader("Vader", 78, 25000, LightSaber_Color::RED, LightSaber_Type::SINGLEBLADED);
    Jedi nikol("Nikol", 20, 500, LightSaber_Color::BLUE, LightSaber_Type::SINGLEBLADED);

    JediCollection myTeam;
    myTeam.AddJedi(yoda);
    myTeam.AddJedi(vader);
    myTeam.AddJedi(nikol);
    //myTeam.removeJedi("nikol");
    //myTeam.printMyJediesInfo();
    JediData curr;
    //curr.sortByPower(myTeam);
    //myTeam.printMyJediesInfo();
    //LightSaber_Color mostRecent = curr.mostPopularSaberColor(myTeam);
    //println("Most recent color saber is: {}", myTeam.getColorName(mostRecent));

    //LightSaber_Type mostRecentT = curr.mostPoplarSaberType(myTeam);
    //println("Most recent saber type is: {}", myTeam.getTypeName(mostRecentT));

    JedilO manager;
    //manager.saveToTxt(myTeam,"myJedies.txt");
    //JediCollection NewTeam = manager.readFromTxt(myTeam, "myJedies.txt");
   // NewTeam.printMyJediesInfo();
    manager.saveToBinary(myTeam, "myJedies.dat");
    JediCollection loadedFromFile = manager.readFromBinary("myJedies.dat");
    loadedFromFile.printMyJediesInfo();
    return 0;
}