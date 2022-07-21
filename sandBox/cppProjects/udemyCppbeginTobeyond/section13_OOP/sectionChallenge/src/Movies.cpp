#include "Movies.h"

// creates a new Movies collection
Movies::Movies (std::string name_val, std::vector<Movie> movies_list_val)
    : name {name_val}, movies {movies_list_val} {};

Movies::~Movies() {};

// sets the name of the collection: e.g. favorites, horrer, comedy, etc...
void Movies::set_class_name(std::string name_val) {
    name = name_val;
};

// adds a movie to the collection inputs are the same values as of the Movie class    
void Movies::add(std::string movie, std::string rating, std::string notes, int watched, double stars) {
    if (!is_in_collection(movie)) {
        Movie new_movie {movie, rating, notes, watched, stars};
        movies.push_back(new_movie);
        std::cout << movie << " added to collection: " << name << std::endl;
    }
    else {
        std::cout << movie << " is already in collection: " << name << std::endl;
    }    
};

// an overloaded movie adder to add the movie by name only
void Movies::add(std::string movie) {
    std::string rating {};
    std::string notes {};
    int watched {};
    double stars {};
    Movies::add(movie, rating, notes, watched, stars);
}

// returns true if a movie name is found in the collection
bool Movies::is_in_collection(std::string movie) {
    for (const Movie &m: movies) {
        if (m.get_name() == movie)
            return true;
    }
    return false;
}

// displays a message that movie is not in collection. Must pass the movie name as an input
void Movies::not_in_collection (std::string movie) {
    std::cout << movie <<  " not in collection: " << name << std::endl;
}

// increments the watched count on a movie in the collection
void Movies::increment(std::string movie) {
    if (is_in_collection(movie)) {
        for (Movie &m: movies) {
            if (m.get_name() == movie) {
                m.increment_watch_count();
            }
        }
    }
    else {
        not_in_collection(movie);
    }
};

// prints the display header for the movies
void Movies::display_header() {
    std::cout << "\nMovie collection: " << name << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    std::cout << "Movie\t\t" << "Rating\t\t" << "Watched Count\t\t" << "Stars\t\t" << "Notes" << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

}

// displays movies in the list
void Movies::display() {
    if (movies.size()>0) {
        display_header();
        for (const Movie &m: movies) {
            m.display();
        }
    }
    else {
        std::cout << "There are no movies in collection: " << name << std::endl;
    }    
};

// an overloaded display that will display info for one movie in collection
void Movies::display(std::string movie) {
    if (is_in_collection(movie)) {
        for (const Movie &m: movies) {
            if (m.get_name() == movie) {
                display_header();
                m.display();
            }
        }
    }
    else {
        not_in_collection(movie);
    }
}

// returns the size of the movie collection
int Movies::get_num_movies() {
    return movies.size();
};

// displays number of times a movie has been watched
void Movies::get_watched_count(std::string movie) {
    if (is_in_collection(movie)) {
        for (Movie &m: movies) {
            if (m.get_name() == movie) {
                std::cout << "You have watched " << movie << " " << m.get_times_watched() << " times." << std::endl;
            }
        }
    }
    else {
        not_in_collection(movie);
    }
};

// Changes the name of a movie in the collection
void Movies::set_name(std::string movie, std::string name_val) {
    if (is_in_collection(movie)) {
        for (Movie &m: movies) {
            if (m.get_name() == movie) {
                m.set_name(name_val);
            }
        }
    }
    else {
        not_in_collection(movie);
    }
};

// adds a note a movie in the collection
void Movies::set_notes(std::string movie, std::string note_val) {
    if (is_in_collection(movie)) {
        for (Movie &m: movies) {
            if (m.get_name() == movie) {
                m.set_note(note_val);
            }
        }
    }
    else {
        not_in_collection(movie);
    }
};

// changes the star rating of a movie in the collection
void Movies::set_stars(std::string movie, double stars_val) {
    if (is_in_collection(movie)) {
        for (Movie &m: movies) {
            if (m.get_name() == movie) {
                m.set_stars(stars_val);
            }
        }
    }
    else {
        not_in_collection(movie);
    }
};

// changes the rating of movie e.g. R PG-13, PG, etc..
void Movies::set_rating(std::string movie, std::string rating_val) {
    if (is_in_collection(movie)) {
        for (Movie &m: movies) {
            if (m.get_name() == movie) {
                m.set_rating(rating_val);
            }
        }
    }
    else {
        not_in_collection(movie);
    }
};

// changes the watched count for a movie in the collection
void Movies::set_watched_count(std::string movie, int watched_val) {
    if (is_in_collection(movie)) {
        for (Movie &m: movies) {
            if (m.get_name() == movie) {
                m.set_watched_count(watched_val);
            }
        }
    }
    else {
        not_in_collection(movie);
    }
};