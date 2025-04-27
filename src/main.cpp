#include <iostream>
#include "rapidjson/document.h"
#include <filesystem>
#include <fstream>
#include <string>
using namespace rapidjson;
using namespace std;

int main()
{
    // read json to char* from file
    auto file = ifstream("1.json");
    cout << typeid(file).name() << endl;
    if (!file.is_open())
    {
        cerr << "Error opening file" << endl;
        return 1;
    }
    auto json = string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    cout << typeid(json).name() << endl;

    auto document = Document();
    cout << json << endl;
    document.Parse(json.data());
    cout << document.IsObject() << endl;

    cout << document["pi"].GetFloat() << endl;
    for (auto& v : document["a"].GetArray())
    {
        cout << v.GetInt();
    }

    return 0;
}
