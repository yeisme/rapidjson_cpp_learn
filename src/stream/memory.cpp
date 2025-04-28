//
// Created by yeisme on 25-4-28.
//
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include <rapidjson/writer.h>
#include <iostream>

using namespace rapidjson;
using namespace std;

int main()
{
    // 输入
    constexpr char json[] = "[1, 2, 3, 4]";
    StringStream s(json);

    cout << s.Peek() << "\n";

    Document d;
    d.ParseStream(s);

    cout << d.Size() << "\n";

    // 输出
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    cout << buffer.GetString() << endl;
}
