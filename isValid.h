#include <bits/stdc++.h> 
using namespace std; 


bool notInRow(int m[][9], int row) 
{ 
	set<int> st; 

	for (int i = 0; i < 9; i++) { 

		if (st.find(m[row][i]) != st.end()) 
			return false; 

		if (m[row][i] != 0) 
			st.insert(m[row][i]); 
	} 
	return true; 
} 

bool notInCol(int m[][9], int col) 
{ 
	set<int> st; 

	for (int i = 0; i < 9; i++) { 

		if (st.find(m[i][col]) != st.end()) 
			return false; 

		if (m[i][col] != 0) 
			st.insert(m[i][col]); 
	} 
	return true; 
} 

bool notInBox(int m[][9], int startRow, int startCol) 
{ 
	set<int> st; 

	for (int row = 0; row < 3; row++) { 
		for (int col = 0; col < 3; col++) { 
			int curr = m[row + 3*startRow][col + 3*startCol]; 

			if (st.find(curr) != st.end()) 
				return false; 

			if (curr != 0) 
				st.insert(curr); 
		} 
	} 
	return true; 
} 

bool isValid(int m[][9], int row, int col) 
{ 
	return notInRow(m, row) && notInCol(m, col) && 
		notInBox(m, row/3, col/3); 
} 

bool isValidConfig(int m[][9], int n) 
{ 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) { 

			if (!isValid(m, i, j)) 
				return false; 
		} 
	} 
	return true; 
} 