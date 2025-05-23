#pragma once

template <typename T>
class Entity
{
private:
    unsigned int m_id;
    static unsigned int m_counter;

public:
    Entity()
    :
    m_id(m_counter++)
    {}
    Entity(const unsigned int id)
    :
    m_id(id)
    {
        if (m_counter <= id)
            m_counter = id + 1;
    }
    virtual ~Entity() = default;
public:
    unsigned int getId() const { return m_id; }

};

template <typename T>
unsigned int Entity<T>::m_counter = 1;
