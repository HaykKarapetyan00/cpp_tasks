#include <QCoreApplication>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int arr[10] = {1, 4, 2, 6, 7, 4, 2, 1, 3, 4};

    for(int i = 0; i < 10; ++i) {
        for(int j = i + 1; j < 10; ++j) {
            if(arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    std::cout << "arr example:" << std::endl;

    std::cout << "min: " << arr[0] << " median: " << arr[4] << " max: " << arr[9] << std::endl;

    std::string str1 = "Hello";
    std::string str2 = "World";

    std::string concatenatedStr = str1 + " " + str2;

    int lengthStr1 = str1.length();
    int lengthStr2 = str2.length();
    int lengthConcatenatedStr = concatenatedStr.length();

    std::cout << "String 1: " << str1 << ", Length: " << lengthStr1 << std::endl;
    std::cout << "String 2: " << str2 << ", Length: " << lengthStr2 << std::endl;
    std::cout << "Concatenated String: " << concatenatedStr << ", Length: " << lengthConcatenatedStr << std::endl;

    return a.exec();
}
