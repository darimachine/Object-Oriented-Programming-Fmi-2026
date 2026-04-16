#pragma once
#include  <compare>
constexpr  int PLACE_MAX_LEN = 2;
constexpr  int INTEGERS_LEN = 4;
constexpr int SYMBOLS_LEN = 2;
constexpr  int REG_NUM_MAX_LEN = 8;
class Registration

{
    private:
        char registrationNum[REG_NUM_MAX_LEN + 1]{'\0'};

        bool isDigit(const char);
        bool isLetter(const char);



    public:
        Registration() = delete;
        Registration(const char*);
        const char* getRegNumb() const;

        friend  std::ostream& operator<<(std::ostream&, const Registration&);
        std::strong_ordering operator<=>( const Registration&) const;
        friend bool operator==(const Registration&, const Registration&) ;
        std::strong_ordering operator<=>(const Registration&);
};

