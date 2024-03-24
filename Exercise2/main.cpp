#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

//inizializzo una funzione che mi mappa i valori da [1,5] a [-1,2]:

double mapValue(double val){
    return (val - 1) * (3.0/4.0) - 1;
}


int main()
{
    std::string fileName = "data.csv"; // leggo il file
    std::ifstream ifstr(fileName);     // creo l'oggetto istream e apro il file

    // eseguo un controllo sull'esistenza del file

    if(ifstr.fail()){
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    std::ofstream outputFile("result.csv");

    // eseguo un controllo :

    if(outputFile.fail()){
        std::cerr << "Error: Cannot create output file" << std::endl;
        return 1;
    }

    //header:
    outputFile << "# N Mean" << "\n";


    // inizializzo le variabili:

    double val;
    double sum = 0;
    unsigned int countVal = 0;
    double mean = 0;


    while(ifstr >> val){
        val = mapValue(val);
        sum += val;
        countVal++;


        mean = sum / countVal;
        outputFile << countVal << " " << std::scientific << std::setprecision(16) << mean << "\n";

    }

    ifstr.close();
    outputFile.close();

    std::cout << "The results are written in the file result.csv" << std::endl;

    return 0;
}
