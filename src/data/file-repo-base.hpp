#pragma once

#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

#define FILE_SEPARATOR '\x1F'

template <typename T>
class FileRepoBase
{
private:
    std::string m_fileName;

protected:
    std::vector<T*> m_entities;
protected:
    FileRepoBase(const std::string fileName)
    :
        m_fileName(fileName)
    {}
protected:

    virtual std::string entityToString(T* ent) = 0;
    virtual T* stringToEntity(const std::string record) = 0;

public:
    virtual ~FileRepoBase() = default;

    void save()
    {
        std::ofstream fout(m_fileName);

        if (!fout.is_open())
            throw std::runtime_error("Error: failed to open file - " + m_fileName);

        for (unsigned int i = 0; i < m_entities.size(); ++i)
            fout << entityToString(m_entities[i]) << '\n';
    }
    void load()
    {
        std::ifstream fin(m_fileName);

        if (!fin.is_open())
            return;

        std::string record;
        while (std::getline(fin, record))
        {
            if (record.empty())
                continue;

            T* ent = stringToEntity(record);

            if (ent != nullptr)
                m_entities.push_back(ent);
        }
    }
    
};
