
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;


class Location{
public:
    int row;
    int col;
    //Location(int r, int c): row(r),col(c){}
};

class Board{
public:
    Board(int r, int c);
    void display();
    void findDistances(int kRow, int kCol);

private:
    int rows;
    int cols;
    vector<vector<int>> b;
};

Board::Board(int r, int c){
    rows = r;
    cols = c;
    b = (vector<vector<int>>(r, vector<int>(c, -1)));
}

void Board::display(){

    for (int r =0; r < rows; r++){
        for(int c=0; c <cols; c++){
            cout << b[r][c] << "\t";
        }
        cout <<endl;
    }
}
void Board::findDistances(int r, int c){
    vector<Location> current;
    vector<Location> newLocations;
    Location loc;
    int newRow, newCol;
    Location newLoc;

    loc.row = r;
    loc.col = c;
    b[r][c] = 0;
    
    current.push_back(loc);
    int dirRow[] = {-2,-2,2,2,1,1,-1,-1};
    int dirCol[] = {-1,1,-1,1,-2,2,-2,2};

    while (current.size() > 0){
        Location L = current.front();
    
        current.erase(current.begin());

        for (int i = 0; i < 8; i++){        
            newRow = L.row + dirRow[i];
            newCol = L.col + dirCol[i];
            newLoc.row = newRow;
            newLoc.col = newCol;
            
            if (newRow >= 0 && newCol >= 0 && newRow <rows && newCol <cols && b[newRow][newCol] ==-1){
                b[newRow][newCol] = b[L.row][L.col]+1;
                current.push_back(newLoc);
            }
        }

        
    }

}

int main(void) {
    ifstream infile;
    infile.open("kcTests.txt");
    int numCases;
    int numRows, numCols, pawnRow, pawnCol, knightRow, knightCol;

    infile >>numCases;

    for(int i=0; i < numCases; i++){
        infile >> numRows;
        infile >> numCols;
        infile >> pawnRow;
        infile >> pawnCol;
        infile >> knightRow;
        infile >> knightCol;

        cout << "Test: " <<endl;
        cout << numRows <<" " << numCols <<endl; 
        cout << pawnRow <<" "<<pawnCol <<endl;
        cout << knightRow <<" "<<knightCol <<endl;
        cout <<endl;

        Board b = Board(numRows, numCols);
        b.findDistances(knightRow,knightCol);
        b.display();
    
    }
    infile.close();
    return 0;
}