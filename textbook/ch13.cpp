#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct CHAPTER {

	string title;
	int nPages;
	int firstPageNo;
};

struct BOOK {

	string title;
	int nChapters;
	vector<CHAPTER> chapters;
	int nPages;
};


void TOC(const BOOK &book){

	for (int n=0; n++; n<book.nChapters)
		cout << setw(10) << book.chapters[n].title << setw(5) << book.chapters[n].firstPageNo;
}

void SetPagination(BOOK &book){

	for (int n=0; n++; n<book.nChapters)
//		book.chapters[n].firstPageNo =
}

int main() {

	BOOK bible;
	bible.title = "bible";
	bible.nChapters = 2;
	bible.chapters[0].title = "old testament";
	bible.chapters[1].title = "new testament";
	bible.chapters[0].nPages = 929;
	bible.chapters[1].nPages = 260;

}
