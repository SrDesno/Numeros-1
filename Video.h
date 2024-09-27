//Edmundo Ruelas Angulo - A01742824
#ifndef VIDEO_H
#define VIDEO_H
//Se incluyen las librerias necesarias
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <locale>
#include <codecvt>
#include <vector>
#include <cstdlib>


class Video {
private:
    //Se crean los atributos de la clase
    int id;
    std::string type;
    std::string title;
    std::string genre;
    std::string overview;
    std::string runtime;
    double vote_average;
    int vote_count;
    int temp_Id;
    std::vector<Video> videos;
public:
    //Constructor por defecto y constructor con parametros
    Video();
    Video(int, std::string, std::string, std::string, std::string, std::string, double, int);
    //Metodo para mostrar la informacion de los objetos
    virtual void showInfo();
    virtual void showInfo_adicional();
    //Metodos getters
    int getId();
    std::string getType();
    std::string getTitle();
    std::string getGenre();
    std::string getOverview();
    std::string getRuntime();
    double getVote_average();
    int getVote_count();
    void setId(int);
    void setTitle(std::string);
    void setVote_average(double);
    void setVote_count(int);
    //Metodo para crear el vector y asignar los valores del .txt a los atributos de la clase
    virtual void createVector();
    //Metodo para imprimir todos los objetos de la clase video
    virtual void showVideo();
    Video*findVideoById(int);
    void mainMenu();
    void menuDetails();
    void functionQualify();
    void menuQualify();
    void saveToFile();
};



#endif //VIDEO_H
