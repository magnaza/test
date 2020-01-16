#include <QCoreApplication>
#include <iostream>
#define N 10
using namespace std;
void create_matrix(int [N][N]);
void create_vector(int [N][N], vector<int>);
void print_matrix(int [N][N]);
void print_vector(vector<int>);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int matrix[N][N];
    vector<int> Vector;
    Vector.resize(N*N);
    string String;
    size_t pos;

    //used while() in order to implement the decision of the user

    while(1){
        cout << "\"crate_matrix\": to create a matrix\n"
                "\"create_vector\": to copy data of matrix in vector\n"
                "\"break\": to exit the program\n"
                "\"print_matrix\": to print the matrix\n"
                "\"print_vector\": to print the vector\n\n";
        cin >> String;
        if(!String.compare("create_matrix"))
            create_matrix(matrix);
        else if(!String.compare("create_vector")){
            for(size_t i=0;i<N;i++){
                for(size_t j=0;j<N;j++){
                    pos=(i*N + j);  //calculate position on vector given the position on the matrix
                    Vector[pos]=matrix[i][j];
                }
            }
            cout << "vector created successfully\n\n";
        }
        else if(!String.compare("break"))
            break;
        else if(!String.compare("print_matrix"))
            print_matrix(matrix);
        else if(!String.compare("print_vector")){
            for(size_t i=0;i<N*N;i++){
                if((i%N) == 0)
                    cout << "\n";
                cout << Vector[i];
            }
            cout << "\n\n";
        }
        else
            cout << "command unkown... try again\n\n\n";
    }
    return a.exec();
}
void create_matrix(int matrix[N][N]){
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            matrix[i][j]=rand()%10+1;
        }
    }
    cout << "matrix created successfully\n\n";
}
void create_vector(int matrix[N][N], vector<int> Vector){
    for(size_t i=0;i<N;i++){
        for(size_t j=0;j<N;j++){
            size_t pos=(i*N + j);  //calculate position on vector given the position on the matrix
            Vector[pos]=matrix[i][j];
        }
    }
    cout << "vector created successfully\n\n";
}
void print_matrix(int matrix [N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << matrix[i][j];
        }
        cout << "\n";
    }
    cout << "\n\n";
}

//print the 1 dim vector like a matrix... each N element is isert \n

void print_vector(vector<int> Vector){
    for(size_t i=0;i<N;i++){
        if((i%N) == 0)
            cout << "\n";
        cout << Vector[i];
    }
    cout << "\n\n";
}
