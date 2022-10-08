#include "Node.h"
#include<cstring>
char* Node::GetEnglish()
{
    return m_english;
}

char* Node::GetRussian()
{
    return m_russian;
}

void Node::SetRussian(const char* buff)
{
    int size = strlen(buff);
    if (size > 14) {
        size = 14;
    }
    int i = 0;
    for (; i < size; i++) {
        m_russian[i] = buff[i];
    }
    m_russian[size] = '\0';
   
   
}