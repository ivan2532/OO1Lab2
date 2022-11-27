#include "PrintingOffice.h"

PrintingOffice::PrintingOffice(std::string pictureNames[], int arraySize)
    :
    m_PictureNamesSize(arraySize)
{
    delete[] m_PictureNames;

    m_PictureNames = new std::string[m_PictureNamesSize];
    for (int i = 0; i < m_PictureNamesSize; i++)
        m_PictureNames[i] = pictureNames[i];
}

PrintingOffice::~PrintingOffice()
{
    delete[] m_PictureNames;
}

PrintingOffice::PrintingOffice(PrintingOffice&& value) noexcept
{
    *this = std::move(value);
}

PrintingOffice& PrintingOffice::operator=(PrintingOffice&& rhs) noexcept
{
    if (this != &rhs)
    {
        delete[] m_PictureNames;

        m_PictureNamesSize = rhs.m_PictureNamesSize;
        m_PictureNames = rhs.m_PictureNames;
        rhs.m_PictureNames = nullptr;
    }

    return *this;
}

Picture* PrintingOffice::PrintPicture(int number) const
{
    if (number < 0 || number >= m_PictureNamesSize)
        return nullptr;

    return new Picture(number, m_PictureNames[number]);
}
