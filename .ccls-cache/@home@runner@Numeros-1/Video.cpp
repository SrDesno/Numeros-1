//Edmundo Ruelas Angulo - A01742824
// Video.cpp
#include "Video.h"

//Constructor por defecto
Video::Video() {
    id = 0000;
    type = "N/O";
    title = "N/O";
    genre = "N/O";
    overview="N/0";
    runtime="N/O";
    vote_average=0;
    vote_count=0;
}

//Constructor con parametros
Video::Video(int _id, std::string _type, std::string _title, std::string _genre, std::string _overview, std::string _runtime, double _vote_average, int _vote_count){
    id = _id;
    type = _type;
    title = _title;
    genre = _genre;
    overview=_overview;
    runtime=_runtime;
    vote_average=_vote_average;
    vote_count=_vote_count;
}

//Metodos getters
int Video::getId() {
    return id;
}

std::string Video::getType() {
    return type;
}

std::string Video::getTitle() {
    return title;
}

std::string Video::getGenre() {
    return genre;
}

std::string Video::getOverview() {
    return overview;
}

std::string Video::getRuntime() {
    return runtime;
}

double Video::getVote_average() {
    return vote_average;
}

int Video::getVote_count() {
    return vote_count;
}

void Video::setId(int _id) {
    id = _id;
}

void Video::setTitle(std::string _title) {
    title = _title;
}

void Video::setVote_average(double _vote_average) {
    vote_average = _vote_average;
}

void Video::setVote_count(int _vote_count) {
    vote_count = _vote_count;
}

//Metodo para mostrar la informacion de los objetos
void Video::showInfo() {
    std::cout << "ID: " << id << "\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Genre: " << genre << "\n";
}

void Video::showInfo_adicional() {
    std::cout << "ID: " << id << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout<<"Overview: "<<overview<<"\n";
    std::cout<<"Runtime: "<<runtime<<"\n";
    std::cout<<"Vote Average: "<<vote_average<<"\n";
}


//Metodo para crear el vector y asignar los valores del .txt a los atributos de la clase
void Video::createVector() {
    //Se abre el archivo con la ruta espesisificada
    std::ifstream archive("video.txt");
    //Se crean las variables necesarias
    std::string line;
    //Se verifica si el archivo se abrio correctamente
    if (archive.is_open()) {
        //Se ignora la primer linea del .txt porque son los encabezados
        std::getline(archive, line);
        //Se recorre el archivo con un ciclo while para recorrer el .txt
        while (std::getline(archive, line)) {
            std::stringstream ss(line);
            std::string data;

            std::getline(ss, data, ';');
            id = std::stoi(data);

            std::getline(ss, type, ';');
            std::getline(ss, title, ';');
            std::getline(ss, genre, ';');
            std::getline(ss,overview,';');
            std::getline(ss,runtime,';');

            std::getline(ss,data,';');
            vote_average=std::stod(data);

            std::getline(ss,data,';');
            vote_count=std::stoi(data);


            //Se crea un nuevo objeto con los datos obtenidos del .txt y se agrega al vector
            videos.push_back(Video(id, type, title, genre, overview, runtime, vote_average, vote_count));
        }
        archive.close();

    }
    //En caso de que no se pueda abrir el archivo se imprime un mensaje
    else {
        std::cout << "Cannot open the archive.\n";
    }
}

//Metodo para imprimir todos los objetos de la clase video
void Video::showVideo() {
    for (auto& video : videos) {
        video.showInfo();
        std::cout << "-----------------------\n";
    }
}

Video* Video::findVideoById(int _id) {
    for (auto& video : videos) {
        if (video.getId() == _id) {
            return &video;
        }
    }
    return nullptr;
}

void Video::saveToFile() {
    std::ofstream outfile("video.txt"); // Open the file for writing
    // Write the header line
    outfile << "'id';'type';'title';'genres';'overview';'runtime';'vote_average';'vote_count'\n"; 
    // Write the data for each video in the vector
    for (auto& video : videos) {
        outfile << video.getId() << ";"
                << video.getType() << ";"
                << video.getTitle() << ";"
                << video.getGenre() << ";"
                << video.getOverview() << ";"
                << video.getRuntime() << ";"
                << video.getVote_average() << ";"
                << video.getVote_count() << "\n";
    }
    outfile.close(); // Close the file
}

void Video::menuDetails() {
    int idmenu;
    std::cout << "-----------------------\n";
    std::cout<<"Enter the ID of the video you want to see the details: ";
    std::cin>>idmenu;
    temp_Id=idmenu;

    Video* video = Video::findVideoById(idmenu);
    if (video != nullptr) {
        video->showInfo_adicional();
        menuQualify();
    }
    else {
        std::cout<<"Video not found\n";
    }
}

void Video::mainMenu() {
    int option;
    createVector();
    showVideo();
    do {
        std::cout<<"1. Show Video details\n";
        std::cout<<"2. Exit\n";
        std::cout<<"Choose an option: ";
        std::cin>>option;

        switch (option) {
            case 1:
                menuDetails();
                break;
            case 2:
                std::cout << "-----------------------\n";
                std::cout<<"Goodbye\n";
                exit(0);
                break;
            default:
                std::cout<<"Invalid option\n";
                break;
        }
    }
    while (option != 2);
}

void Video::functionQualify() {
    double qualify;
    std::cout << "-----------------------\n";
    std::cout << "Qualify the video from 1 to 5: ";
    std::cin >> qualify;

    Video* video = Video::findVideoById(temp_Id);
    if (video == nullptr) {
        std::cout << "Video not found\n";
        return;
    }

    if (qualify >= 1 && qualify <= 5) {
        int new_vote_count = video->getVote_count() + 1;
        double new_vote_average = ((video->getVote_average() * video->getVote_count()) + qualify) / new_vote_count;
        video->setVote_count(new_vote_count);
        video->setVote_average(new_vote_average);

        std::cout << "-----------------------\n";
        std::cout << "The video has been qualified\n";
        std::cout << "The new average is: " << video->getVote_average() << "\n";
        saveToFile();

    } else {
        std::cout << "-----------------------\n";
        std::cout << "Invalid qualification\n";
    }
}

void Video::menuQualify() {
    int option;
    do {
        std::cout << "-----------------------\n";
        std::cout<<"1. Qualify video\n";
        std::cout<<"2. Go to main menu\n";
        std::cout<<"3. Exit program\n";
        std::cout<<"Choose an option: ";
        std::cin>>option;

        switch (option) {
            case 1:
                functionQualify();
                break;
            case 2:
                mainMenu();
                break;
            case 3:
                std::cout<<"Goodbye\n";
                exit(0);
                break;
        }
    }
    while (option != 3);
}