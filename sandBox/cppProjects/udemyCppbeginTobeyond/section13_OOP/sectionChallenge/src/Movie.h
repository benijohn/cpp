#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <iostream>
#include <string>

class Movie {
    private:
    std::string name;
    std::string rating;
    std::string notes;

    int watched;
    double stars;

    public:
    std::string get_name() const;
    std::string get_rating();
    std::string get_notes();
    int get_times_watched();
    double get_stars();

    void set_name(std::string name_val);
    void set_rating(std::string rating_val);
    void set_note(std::string note_val);
    void set_watched_count(int watched_val);
    void increment_watch_count();
    void set_stars(double stars_val);

    void display() const;

    Movie (std::string name_val = "None", std::string rating_val = "None", std::string note_val = "None", int watched_val = 0, double stars_val = 0);
    //Movie (const Movie &source);
    ~Movie();

    friend class Movies;
};


#endif