#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>

const int CELL_SIZE = 20;
const int WIDTH = 30;
const int HEIGHT = 30;

enum Direction {
    N, E, S, W
};
class Cell {
public:
bool left;
bool right;
bool down;
bool up;
bool visited;
	Cell():  left(true), right(true), up(true), down(true), visited(true) {}
};

class Maze {
public:
    Maze(int width, int height);
    void generateMaze(sf::RenderWindow& window);

private:
    void destroywalls(int x, int y, int nx, int ny);
    int width;
    int height;
    std::vector<std::vector<Cell>> grid;
    std::stack<std::pair<int, int>> frontier;

    void addStack(int x, int y);
    void mark(int x, int y);
    std::vector<std::pair<int, int>> getNeighbors(int x, int y);
};

Maze::Maze(int width, int height) : width(width), height(height), grid(width, std::vector<Cell>(height)) {
    std::srand(static_cast<unsigned>(time(nullptr)));
}

void Maze::addStack(int x, int y) {
    if (x >= 0 && y >= 0 && y < height && x < width) {
        frontier.push(std::make_pair(x, y));
    }
}

void Maze::mark(int x, int y) {
    grid[x][y].visited = false; // visited
}

std::vector<std::pair<int, int>> Maze::getNeighbors(int x, int y) {
    std::vector<std::pair<int, int>> n;

    if (x > 0 && grid[x-1][y].visited) {
        n.push_back(std::make_pair(x - 1, y));
    }
    if (x + 1 < width && grid[x+1][y].visited) {
        n.push_back(std::make_pair(x + 1, y));
    }
    if (y  > 0 && grid[x][y-1].visited) {
        n.push_back(std::make_pair(x, y - 1));
    }
    if (y + 1 < height && grid[x][y+1].visited){
        n.push_back(std::make_pair(x, y + 1));
    }

    return n;
}

void Maze::destroywalls(int x, int y, int nx, int ny){
	    if(x-nx>0){
            grid[x][y].left = false;
            grid[x-1][y].right = false;
            }
            if(x-nx<0){
            grid[x][y].right = false;
            grid[x+1][y].left = false;
            }
            if(y-ny>0){
            grid[x][y].down = false;
            grid[x][y-1].up = false;
            }
            if(y-ny<0){
            grid[x][y].up = false;
            grid[x][y+1].down = false;
            }
}
            

void Maze::generateMaze(sf::RenderWindow& window) {
    window.clear();
    int x = rand() % width;
    int y = rand() % height;
    mark(x, y);
    addStack(x,y);
    do {
    	
        std::vector<std::pair<int, int>> n = getNeighbors(x, y);
        if (!n.empty()) {
            std::pair<int, int> neighbor = n[rand() % n.size()];
            int nx = neighbor.first;
            int ny = neighbor.second;
            
            destroywalls(x,y,nx,ny);
            x=nx;
            y=ny;
            mark(x, y);
            addStack(x, y);
            }
            else{
            x = frontier.top().first;
            y = frontier.top().second;
            frontier.pop();
            }
            
        

        
    }while (!frontier.empty());
    // Draw the maze
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[j][i].down) {
                    sf::Vertex line[] = {
                        sf::Vertex(sf::Vector2f(j * CELL_SIZE, (i + 1) * CELL_SIZE)),
                        sf::Vertex(sf::Vector2f((j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE))
                    };
                    window.draw(line, 2, sf::Lines);
                }
                if (grid[j][i].right) {
                    sf::Vertex line[] = {
                        sf::Vertex(sf::Vector2f((j + 1) * CELL_SIZE, i * CELL_SIZE)),
                        sf::Vertex(sf::Vector2f((j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE))
                    };
                    window.draw(line, 2, sf::Lines);
                }
               
                }
        }

        window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH * CELL_SIZE, HEIGHT * CELL_SIZE), "Maze Generator");
    window.setFramerateLimit(60);

    Maze maze(WIDTH, HEIGHT);
    maze.generateMaze(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}
