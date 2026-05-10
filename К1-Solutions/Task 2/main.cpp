#include <iostream>
#include "Hospital.h"
using namespace std;

int main() {
    Hospital& hosp = Hospital::getInstance();

    string cardiology = "Кардиология";
    string nevrology = "Неврология";
    hosp.addWard(cardiology);
    hosp.addWard(nevrology);

    auto patient = make_shared<Patient>("Serhan", "1231321", "Good", 12);

    hosp[cardiology].addPatient(patient);
    hosp[nevrology].addPatient(patient);  // същият пациент в двете отделения

    // Верижно обновяване на диагноза:
    hosp[cardiology]("1231321", "Хипертония")("1231321", "Аритмия");

    std::cout << hosp << "\n";
    cout << "В колко отделения е пациентът: "
        << hosp.countPatientWards("1231321") << "\n";

    auto wards = hosp.findPatientInWards("1231321");
    for (const auto& w : wards)
        cout << "Намерен в: " << w.getName() << "\n";
    // wards е списък с отделенията, в които е намерен пациентът

    if (!hosp)
        std::cout << "Болницата не е пренаселена\n";

}
