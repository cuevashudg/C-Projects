#include <iostream>
#include <iomanip>

using namespace std;

// Length conversion
double metersToFeet(double meters) {
    return meters * 3.28084;
    }
double feetToMeters(double feet) {
    return feet / 3.28084;
    }

// Weight conversion
double kilogramsToPounds(double kg) {
    return kg * 2.20462;
    }
double poundsToKilograms(double lb) {
    return lb / 2.20462;
    }

// Temperature conversion
double celsiusToFahrenheit(double c) { 
    return c * 9.0 / 5.0 + 32;
    }
double fahrenheitToCelsius(double f) {
    return (f - 32) * 5.0 / 9.0;
    }

int main() {
    int choice;
    cout << "Unit Converter\n";
    cout << "1. Length (meters <-> feet)\n";
    cout << "2. Weight (kilograms <-> pounds)\n";
    cout << "3. Temperature (Celsius <-> Fahrenheit)\n";
    cout << "Choose conversion type (1-3): ";
    cin >> choice;

    double input, result;
    switch (choice) {
        case 1:
            cout << "1. Meters to Feet\n2. Feet to Meters\nChoose (1-2): ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter meters: ";
                cin >> input;
                result = metersToFeet(input);
                cout << fixed << setprecision(4) << input << " meters = " << result << " feet\n";
            } else {
                cout << "Enter feet: ";
                cin >> input;
                result = feetToMeters(input);
                cout << fixed << setprecision(4) << input << " feet = " << result << " meters\n";
            }
            break;
        case 2:
            cout << "1. Kilograms to Pounds\n2. Pounds to Kilograms\nChoose (1-2): ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter kilograms: ";
                cin >> input;
                result = kilogramsToPounds(input);
                cout << fixed << setprecision(4) << input << " kg = " << result << " lb\n";
            } else {
                cout << "Enter pounds: ";
                cin >> input;
                result = poundsToKilograms(input);
                cout << fixed << setprecision(4) << input << " lb = " << result << " kg\n";
            }
            break;
        case 3:
            cout << "1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\nChoose (1-2): ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter Celsius: ";
                cin >> input;
                result = celsiusToFahrenheit(input);
                cout << fixed << setprecision(2) << input << " C = " << result << " F\n";
            } else {
                cout << "Enter Fahrenheit: ";
                cin >> input;
                result = fahrenheitToCelsius(input);
                cout << fixed << setprecision(2) << input << " F = " << result << " C\n";
            }
            break;
        default:
            cout << "Invalid choice.\n";
    }
    return 0;
}