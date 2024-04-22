#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <numbers>
#include <Windows.h>
#include "WorkingWithADictionary.h"
//������������ ������ �� ������� �����


void AddWord(std::string const& word, IO& io, Dictionary& dictonary)
{
    std::string ruWord = "";
    std::cout << "����������� ����� " << word << " ������� ������� ��� ������ ������ ��� ������." << std::endl;
    if (getline(io.in, ruWord) && ruWord != "")
    {
        dictonary.emplace(word, ruWord);
        std::cout << "����� " << word << " ��������� � ��������� " << ruWord << std::endl;
    }
}

//void!!!
void WorkingWithDictionary(Dictionary& dictonary, IO& io)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string word;
    while (getline(io.in, word) && word != "...")
    {
        //������������ find ��� ������
        if (auto search = dictonary.find(word); search == dictonary.end())
        {
            //�������� � ��������� �������
            AddWord(word, io, dictonary);
        }
        else
        {
            io.out << search -> second;
            std::cout << std::endl;
        }
    }
}

//���� � ����� ������� �� �������
// ����������� ������!!
bool SaveDictionary(Dictionary const& dictonary, std::string const& dictonaryFilePath)
{
    std::ofstream outFile;
    outFile.open(dictonaryFilePath);
    if (outFile.is_open())
    {
        for (const auto& pair : dictonary)
        {
            outFile << pair.first << " " << pair.second << std::endl;
        }
        std::cout << "������ ���� ������� �������� � ����." << std::endl;
    }
    else
    {
        std::cerr << "���������� ������� ���� ��� ������." << std::endl;
        return false;
    }
    return true;
}

bool DictionaryWorking(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //������� ����
    std::string dictonaryFilePath = "Dictonary.txt";
    bool args = ParseArg(argc, argv, dictonaryFilePath);
    if (!args)
    {
        std::cout << "Error parse arg" << std::endl;
        return false;
    }
    Dictionary dictonary;
    bool correctReadDictonary = ReadDictonary(dictonaryFilePath, dictonary);
    if (!correctReadDictonary)
    {
        std::cout << "Error read dictonary" << std::endl;
        return false;
    }
    IO io{ std::cin, std::cout };
    size_t sizeDictionaryBeforeWorking = dictonary.size();
    WorkingWithDictionary(dictonary, io);

    size_t sizeDictionaryAfterWorking = dictonary.size();
    if (sizeDictionaryAfterWorking > sizeDictionaryBeforeWorking)
    {
        bool correctSaveDictionary = SaveDictionary(dictonary, dictonaryFilePath);
        if (!correctSaveDictionary)
        {
            std::cout << "Error Save Dictonary" << std::endl;
            return false;
        }
    }
    return true;
}