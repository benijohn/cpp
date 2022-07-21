#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <iostream>
#include <string>
#include <vector>
#include "Movie.h"
#include "Movie.cpp"

class Movies {
    private:
    std::string name;
    std::vector<Movie> movies;
    bool is_in_collection(std::string movie);
    void not_in_collection(std::string movie);
    void display_header();

    public:
    void set_class_name(std::string name_val);
    // add movies to the list
    void add(std::string movie, std::string rating, std::string notes, int watched, double stars);
    void add(std::string movie);
    
    // display movie information
    void display(); // whole list
    int get_num_movies(); // number of movies in list (size of vector)

    // methods acting on Movie objects;
    void display(std::string movie); // single movie
    void set_name(std::string movie, std::string name_val); // set movie name
    void set_notes(std::string movie, std::string note_val); // add notes to movie
    void set_stars(std::string movie, double stars_val); // set movie stars rating
    void set_rating(std::string movie, std::string rating_val); // set movie actual rating
    void set_watched_count(std::string movie, int watched_val); // set movie watched count
    void increment(std::string movie); // increment movie watched count
    void get_watched_count(std::string movie); // number of times a movie by name has been watched

    // Constructor
    Movies (std::string name_val = "None", std::vector<Movie> movies_list_val = {});
    // Destructor
    ~Movies();
};


#endif