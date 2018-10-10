// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 2
// Program: CS213-2018-A1-T1-P2
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0
#include <iostream>
#include <iomanip>
#include <valarray>
//#include <cassert>
using namespace std;



// A structure to store a matrix
struct matrix
{
    valarray<int>data;       //valarray that will simulate matrix
    int row, col;
};


// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
    int data1 [] = {1,0,0,0,1,0,0,0,1};
    //int data1 [] = {13,233,3,4,5,6,3,5,7};
    int data2 [] = {13,233,2,7,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    matrix mat1, mat2, mat3 ;
    //createMatrix (4, 2, data1, mat1);
    createMatrix (3, 3, data1, mat1);
    createMatrix (3, 2, data2, mat2);
    createMatrix (2, 4, data3, mat3);
    //cout<<mat2;
   // cout<<transpose( mat2);
//cout<<mat1;
     //cout<<isSymetric (mat1);
    //cout<<isIdentity (mat1);



    //isSymetric (mat1);
   // cout<<isIdentity ( m);  // True if square and identity


    /* The next code will not work until you write the functions
      cout << mat1 << endl;
      cout << mat2 << endl;
      cout << mat3 << endl;

      cout << (mat1 + mat3) << endl << endl;
      cout << (mat3 + mat3) << endl << endl;

      ++mat1;
      cout << mat1 << endl;

      mat1+= mat3 += mat3;
      cout << mat1 << endl;
      cout << mat2 << endl;
      cout << mat3 << endl;
      // Add more examples of using matrix
      // .......


}
*/
cout<<isSquare(mat2)<<endl;
cout<<(data1==data2);
 cout<<isIdentity (mat1);
 cout<<isSymetric (mat1);
}
//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data.resize (row * col);
    for (int i = 0; i < row * col; i++){
        mat.data [i] = num [i];
    }


}
bool   operator== (matrix mat1, matrix mat2)
{
    if (( mat1.row ==  mat2.row) && ( mat1.col == mat2.col ))  //if row not equal colum is not eqyal aready
    {
        for(int i=0; i<mat1.row*mat1.col; i++)    //to loop for elements
        {
            if(mat1.data[i] != mat2.data[i])   // i do that to loop for element if i do == do check one elements and out of loop
            {
                return false ;
            }
        }
        return true ;          //print one if it true
    }
    else
        return false ;                  //return false if row not equal colum
}
bool   operator!= (matrix mat1, matrix mat2)
{
        if (( mat1.row ==  mat2.row) && ( mat1.col == mat2.col ))
    {
        for(int i=0; i<mat1.row*mat1.col; i++)
        {
            if(mat1.data[i] == mat2.data[i])
            {
                return false ;
            }
        }
        return true ;
    }
    else
        return false ;
}

    bool   isSquare   (matrix mat)
    {
      if ( mat.row == mat.col ) {
         return true ;

      }
    else
        return false ;


    }





matrix transpose(matrix mat)
{
    matrix mat4;      //creat new matrix to add in it new element whic be transpose
   int *num;
    num=new int[mat.row*mat.col];         //size it new matrix
   createMatrix(mat.col,mat.row,num,mat4);       // i swap betwenn  col and row to print transpose
    cout<<mat4.row<<":"<<mat4.col<<endl;        // print row colum for new matrix i creat to put in it elents which stored in valarray

    for(int i=0;i<mat.row;i++)
    {
        for(int j=0;j<mat.col;j++)
        {
            mat4.data[j*mat.row+i]=mat.data[i*mat.col+j];     //put in new matrix i creat new element which i do transpose for it
        }
    }

    return mat4;     //print transpose matrix

}




ostream& operator<< (ostream& out, matrix mat1)
{ for(int i=0;i<mat1.row;i++){
    for(int j=0;j<mat1.col;j++){
        cout<<mat1.data[i*mat1.col+j];
        cout<<" ";
    }
    cout<<endl;
    }
return out;
}
bool isIdentity (matrix mat)
{


      matrix mat4;
   int *num;
    num=new int[mat.row*mat.col];
   createMatrix(mat.col,mat.row,num,mat4);
    if(mat.row==mat.col){
      for(int i=0;i<mat.row;i++)
      {
        for(int j=0;j<mat.col;j++)
        {
            if(i==j){

            if(mat.data[j*mat.row+i]!=1)

                return false;
            }
            else{
                if (mat.data[j*mat.row+i]!=0)
                    return false;
            }
        }
      }
    }
    return true;
}
bool   isSymetric (matrix mat)
{



 if(mat.row==mat.col){    //to be squar
     for(int i=0;i<mat.row;i++){    //to loop fpr row

    for(int j=0;j<mat.col;j++){ //to loop for colum
            if(mat.data[j*mat.row+i]!=mat.data[i*mat.col+j]){        //if elements in row not elemnts of colum retun false  this to be symatric
                return false;


            }}



    }}

  return true;
 }
















