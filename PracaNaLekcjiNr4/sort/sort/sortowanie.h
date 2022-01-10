#include<vector>
using namespace std;
class sortowanie
{
public:
	sortowanie();
	void wyswietlanie();
	void babelkowy();
	void przez_wybor();
	void sortowanie_std();
	void wstawianie();
	void quick_sort(int left, int right);
	void gen();
	vector <int> liczby_wylosowane;
private:
	int x, i;
};