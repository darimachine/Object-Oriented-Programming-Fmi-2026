#include "Registration.h"
#include <stdexcept>

Registration::Registration(const char *carNum_) {
size_t carLen = strlen(carNum_);

    if (!isValidRegistration(carNum_)) {
       std:: cout << "Invalid car number " << carNum_ << std::endl;
        return;
    }

    for (size_t i = 0; i < carLen; i++) {
        carNum[i]=carNum_[i];
    }
    carNum[carLen] = '\0';
}

Registration::Registration(const Registration &other) {
    copyFrom(other);
}

Registration & Registration::operator=(const Registration &other) {
    if (this == &other) {return* this;}
    carNum[0]='\0';
    copyFrom(other);
    return *this;
}

bool Registration::operator==(const Registration &other) const {
    if (strlen(this->carNum)!=strlen(other.carNum)){return false;}

    for (int i=0; i<strlen(other.carNum); i++) {
        if (other.carNum[i] != carNum[i]) {return false;}
    }

    return true;
}

bool Registration::operator!=(const Registration &other) const {
    return !(*this == other);
}

bool Registration::operator<(const Registration &other) const {
    if (*this == other) {return false;}

    for (int i=0; i<strlen(other.carNum); i++) {
        if (other.carNum[i] < carNum[i]) {return false;}
    }
    return true;

}

bool Registration::operator>(const Registration &other) const {
    if (*this == other) {return false;}
    return !(*this < other);
}

bool Registration::isValidRegistration(const char* carNum_) const {
        int carLen = strlen(carNum_);

        if (carLen != 7 && carLen != 8) return false;
        int i = 0;
        int lettersStart = 0;
        while (i < carLen && isupper(carNum_[i]) && lettersStart < 2) {
            i++;
            lettersStart++;
        }

        if (lettersStart < 1) return false;

        for (int j = 0; j < 4; j++) {
            if (i >= carLen || !isdigit(carNum_[i])) return false;
            i++;
        }

        if (i + 2 != carLen) return false;

        if (!isupper(carNum_[i]) || !isupper(carNum_[i + 1])) return false;

        return true;
}

void Registration::copyFrom(const Registration &other) {
    size_t carLen = strlen(other.carNum);
    for (int i=0; i<carLen; i++) {
        carNum[i]=other.carNum[i];
    }
    carNum[carLen] = '\0';

}

const char * Registration::getCarNum()const {
    return carNum;
}

std::ostream & operator<<(std::ostream &os, const Registration &car) {
os << car.getCarNum();
    return os;
}