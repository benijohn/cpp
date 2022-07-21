#include "Movie.h"


Movie::Movie (std::string name_val, std::string rating_val, std::string note_val, int watched_val, double stars_val)
    : name {name_val}, rating {rating_val}, notes {note_val}, watched {watched_val}, stars {stars_val} {
    }
    
//Movie (const Movie &source);


Movie::~Movie() {
};

std::string Movie::get_name() const {
    return name;
};

std::string Movie::get_rating() {
    return rating;
};
std::string Movie::get_notes() {
    return notes;
};

int Movie::get_times_watched() {
    return watched;
};

double Movie::get_stars() {
    return stars;
};

void Movie::set_name(std::string name_val) {
    name = name_val;
};

void Movie::set_rating(std::string rating_val) {
    rating = rating_val;
};

void Movie::set_note(std::string note_val) {
    notes += "\t" + note_val;
};

void Movie::set_watched_count(int watched_val) {
    watched = watched_val;
};

void Movie::increment_watch_count() {
    ++watched;
};

void Movie::set_stars(double stars_val) {
    stars = stars_val;
};

void Movie::display() const {
    std::cout << name << "\t\t" << rating << "\t\t" << watched << "\t\t" << stars << "\t\t" << notes << std::endl;
}


