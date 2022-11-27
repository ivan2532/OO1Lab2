#ifndef _printing_office_h_
#define _printing_office_h_

#include "Picture.h"

class PrintingOffice
{
public:
	PrintingOffice(std::string pictureNames[], int arraySize);
	~PrintingOffice();

	PrintingOffice(const PrintingOffice&) = delete;

	PrintingOffice(PrintingOffice&&) noexcept;
	PrintingOffice& operator=(PrintingOffice&& rhs) noexcept;

	int GetPictureNamesSize() const { return m_PictureNamesSize; }
	Picture* PrintPicture(int number) const;

private:
	std::string* m_PictureNames;
	int m_PictureNamesSize;
};

#endif // _printing_office_h_