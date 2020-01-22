#include<bits/stdc++.h>
#include "isValid.h"
using namespace std;

bool solve(int m[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(m[i][j]==0){
                for(int v=1;v<=9;v++){
                    m[i][j]=v;
                    if(isValid(m,i,j)){
                        if(!solve(m))
                        continue;
                        else
                        return true;
                    }
                }
                m[i][j]=0;
                return false;
            }
        }
    }
    return true;
}

int main()
 {
        int m[9][9];
        cout<<"Enter a valid sudoku(9x9):"<<endl;
        cout<<"Enter '0' for empty spaces:"<<endl;
	    for(int i=0;i<9;i++)
	        for(int j=0;j<9;j++)
	            cin>>m[i][j];    
        if(!isValidConfig(m,9)){
            cout<<"Sudoku given is NOT valid!!"<<endl;
            exit(1);
        }
        solve(m);
        cout<<"Solved Sudoku:"<<endl;
	    for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<m[i][j]<<" ";	
	        }
	        cout<<endl;
	    }
	return 0;
}