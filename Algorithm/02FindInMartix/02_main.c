#include <iostream>


bool Find(int *matrix, int rows, int columnes, int number)
{

	bool found = false;
	if (matrix != NULL && rows > 0 && columnes > 0){
		int row = 0;
		int columne = columnes - 1;
		while (row < rows && columne >= 0){
			if (matrix[row * columnes + columne] == number){
				found = true;
				break;
			}
			else if (matrix[row * columnes + columne] > number)
				--columne;
			else
				++row;
		}
	}

	return found;

}