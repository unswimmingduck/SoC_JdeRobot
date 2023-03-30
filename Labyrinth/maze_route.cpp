#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

#define MAXSIZE 0xffff

template <class type>

class Route_Stack {
		int top;
		type *data;
		int maxsize;

	public:
		Route_Stack(): top(-1), maxsize(MAXSIZE) {
			data = new type[maxsize];
			if (data == NULL) {
				cout << "Dynamic storage allocation failed!" << endl;
				exit(1);
			}
		}
		Route_Stack(int size): top(-1), maxsize(size) {
			data = new type[maxsize];
			if (data == NULL) {
				cout << "Dynamic storage allocation failed!" << endl;
				exit(1);
			}
		}
		~Route_Stack() {
			delete[] data;
		}
		void Init();				//Init the stack
		bool EmptyStack();			//Check whether the stack is empty, if the stack is empty return true
		type Top();					//Get the object of the top stack
		void Pop();					//Pop the stack
		void Push(type tp);			//Add new object to the stack
		int Size();					//Get the size of the stack
		void Update_Dir(int dir);	//Update a item in the stack
		void Copy_To(Route_Stack *Store);		//Copy the current stack to other stack, !!!this way is a deep copy!!!
};


template <class type>

void Route_Stack<type>::Init() {
	top = -1;
}

template <class type>

bool Route_Stack<type>::EmptyStack() {
	if (top == -1)
		return true;
	else
		return false;
};

template <class type>

type Route_Stack<type>::Top() {
	if (top != -1)
		return data[top];
	else {
		cout << "The stack is empty" << endl;
		exit(1);
	}

};

template <class type>

void Route_Stack<type>::Pop() {
	if (top >= 0)
		top--;
	else {
		cout << "The stack is empty !!!" << endl;
	}

};

template <class type>

void Route_Stack<type>::Push(type tp) {
	if (top + 1 < MAXSIZE)
		data[++top] = tp;
	else {
		cout << "The stack is full !!!" << endl;
		exit(1);
	}

};

template <class type>

int Route_Stack<type>::Size() {
	return top + 1;
};

template <class type>

void Route_Stack<type>::Update_Dir(int dir) {
	data[top].dir = dir;
};

template <class type>

void Route_Stack<type>::Copy_To(Route_Stack *Store) {
	for (int i = 0; i <= top; i++) {
		Store->data[i] = data[i];
	}
	Store->top = top;
};

/////////////////////////////////////////
/////////////////////////////////////////

typedef struct Point {
	int x;
	int y;
	int dir = -1;
} point;

////////////////////////////////////////
////////////////////////////////////////

class Map {
	protected:
		int size;
		char **maze;

		typedef struct Start_End_Info {
			int *location_x;
			int *location_y;
			int num;
			bool kind;
		} Info;

	public:
		Info info[2];


		void read_size(void);		//Get the size of the map;
		void load_map(void);		//Load the map from the file named "maze.txt";
		void search_start(void);	//Search the start location of the map;
		void search_end(void);		//Search the end location of the map;
		void Init(void);

		char **read_maze(void);		//return a two-dimension array, the array contain the infomation of the map;
		int get_size(void);			//return the size of the map;
};

void Map::read_size() {
	int lines = 0;
	string line;
	ifstream in("maze.txt");

	if (in) {
		while (getline(in, line)) {
			lines++;
		}
		size = lines;
		in.close();
		if (size == 0) {
			cout << "Please check the data in the file, there has no maze in the file";
		}

	} else {
		cout << "Please chose the right file";
	}
}


void Map::load_map(void) {
	maze = new char *[size];

	for (int i = 0; i < size; i++) {
		maze[i] = new char [size];
	}

	ifstream file("maze.txt");

	if (file) {
		cout << "The preview of the maze:" << endl;

		while (!file.eof()) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					file >> maze[i][j];
					cout << maze[i][j];
				}
				cout << endl;
			}
			file.close();
			break;
		}
	}
}

void Map::search_start(void) {

	if (size == 0) {
		cout << "Please check the map of maze, there has no maze" << endl;
		cout << "!!! Please use the function of load_map before this functio !!!" << endl;
		exit(1);

	} else {
		info[0].kind = true;
		int i;
		vector<int> S;

		for ( i = 0; i < size; i++) {
			if (maze[0][i] == '.') {
				S.push_back(i);
			}
		}
		int j = 0;
		info[0].location_y = new int [S.size()];
		info[0].location_x = new int [S.size()];
		vector<int>::iterator iter;

		for (iter = S.begin(); iter != S.end(); iter++) {
			info[0].location_y[j] = (*iter);
			info[0].location_x[j] = 0;
			j++;
		}
		info[0].num = j ;
		S.clear();
	}
}

void Map::search_end(void) {

	if (size == 0) {
		cout << "Please check the map of maze, there has no maze" << endl;
		cout << "!!! Please use the function of load_map before this functio !!!" << endl;
		exit(1);

	} else {
		info[1].kind = false;
		vector<int> E;
		int end_location = size - 1;

		for (int i = 0; i < size; i++) {
			if (maze[end_location][i] == '.')
				E.push_back(i);
		}

		int i = 0;
		info[1].location_y = new int [E.size()];
		info[1].location_x = new int [E.size()];
		vector<int>::iterator iter;

		for (iter = E.begin(); iter != E.end(); iter++) {
			info[1].location_y[i] = (*iter);
			info[1].location_x[i] = end_location;
			i++;
		}
		info[1].num = i ;
		E.clear();
	}
}

void Map::Init(void) {
	Map::read_size();
	Map::load_map();
	Map::search_start();
	Map::search_end();
}


char **Map::read_maze(void) {
	return maze;
}

int Map::get_size() {
	return size;
}


///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////

class DFS_Search {
	public:
		char **Copy_Map(Map *M);	//copy the map of maze from the Map class
		void Search_Route(Map *M, Route_Stack<Point> *Current,
		                  Route_Stack<Point> *Store);	//Search every possibilities of the way
		void DFS_Method(int size, char **copy_map, Route_Stack<Point> *Current, Route_Stack<Point> *Store,
		                int start_x, int start_y,
		                int end_x, int end_y); //Use the DFS to search the longest way, in this method we will search 8 directions
		void Show_Result(Map *M, Route_Stack<Point> *Store);	//show the search result
		void Update_Map(char **map, int X_location, int Y_location, char change);	//sign the loaction that we have research
};

void DFS_Search::Update_Map(char **map, int X_location, int Y_location, char change) {
	map[X_location][Y_location] = change;
}


char **DFS_Search::Copy_Map(Map *M) {
	char **copy;
	int s = M->get_size();
	char **m = M->read_maze();
	copy = new char *[s];
	for (int i = 0; i < s; i++) {
		copy[i] = new char [s];
	}
	for (int j = 0; j < s; j++) {

		for (int k = 0; k < s; k++) {
			copy[j][k] = m[j][k];
		}
	}
	return copy;
}

void DFS_Search::DFS_Method(int size, char **copy_map,
                            Route_Stack<Point> *Current, Route_Stack<Point> *store,
                            int start_x, int start_y,
                            int end_x, int end_y) {

	int Longest_Route = 0;

	point Now;
	Now.x = start_x;
	Now.y = start_y;
	Now.dir = -1;

	Current->Push(Now);

	while (!(Current->EmptyStack())) {
		Now = Current->Top();

		if (Now.x == end_x && Now.y == end_y) {		//if we arrive the end, we will assert if this way is the longest

			if (Current->Size() > Longest_Route) {	//if this way is the longest we will store this way into a new stack named store
				Longest_Route = Current->Size();
				Current->Copy_To(store);
			}
			Current->Pop();

		} else {									//if we do not arrive the end, we will search 8 directions to find the possible way
			int dir;
			int next_x, next_y;

			for (dir = Now.dir + 1; dir < 8; dir++) {

				switch (dir) {
					case 0:							// -----|------
						next_x = Now.x;				//	Now | Next
						next_y = Now.y + 1;			// -----|------
						break;
					case 1:							//	Now	|
						next_x = Now.x + 1;			// -----|------
						next_y = Now.y + 1;			//	    | Next
						break;
					case 2:							//	Now |
						next_x = Now.x + 1;			// -----|------
						next_y = Now.y;				//  Next|
						break;
					case 3:							// 		| Now
						next_x = Now.x + 1;			// -----|------
						next_y = Now.y - 1;			//      | Next
						break;
					case 4:							// 		| Now
						next_x = Now.x;				// -----|------
						next_y = Now.y - 1;			// Next |
						break;
					case 5:							// -----|------
						next_x = Now.x - 1;			// Next | Now
						next_y = Now.y - 1;			// -----|------
						break;
					case 6:							// Next |
						next_x = Now.x - 1;			// -----|------
						next_y = Now.y;				//      | Now
						break;
					case 7:							//		| Next
						next_x = Now.x - 1;			//------|------
						next_y = Now.y + 1;			//      | Now
						break;
				}

				//if the Next location is available push the next into the Current stack and update the direction of the Now location
				if ((next_x >= 0) && (next_x < size) && (next_y >= 0) && (next_y < size) && ((copy_map[next_x][next_y]) == '.')) {
					Current->Update_Dir(dir);
					Update_Map(copy_map, Now.x, Now.y, '0');

					point Next;
					Next.x = next_x;
					Next.y = next_y;
					Next.dir = -1;
					Current->Push(Next);
					break;
				}
			}

			if (8 == dir) {									//if the next has no direction to go, we will pop the Current Stack
				Update_Map(copy_map, Now.x, Now.y, '.');
				Current->Pop();
			}
		}
	}
}

void DFS_Search::Search_Route(Map *M, Route_Stack<Point> *Current, Route_Stack<Point> *Store) {
	for (int i = 0; i < M->info[0].num; i++) {				//Go through all the ends and all the starts
		for (int j = 0; j < M->info[1].num; j++) {
			char **maze;
			maze = Copy_Map(M);
			DFS_Method(M->get_size(), maze,
			           Current, Store,
			           M->info[0].location_x[i], M->info[0].location_y[i],
			           M->info[1].location_x[j], M->info[1].location_y[j]);
		}
	}

}


void DFS_Search::Show_Result(Map *M,
                             Route_Stack<Point> *Store) {	//Show the result of the search by going through the Store stack
	cout << "output: " << endl;
	int Size = Store->Size();
	char **copy_map = Copy_Map(M);
	if (Size == 0)
		cout << "-1" << endl;

	while (!(Store->EmptyStack())) {
		Update_Map(copy_map, (Store->Top()).x, (Store->Top()).y, char(Size + 48));
		Size--;
		Store->Pop();
	}
	for (int j = 0; j < M->get_size(); j++) {
		for (int k = 0; k < M->get_size(); k++) {
			cout << copy_map[j][k];
		}
		cout << endl;
	}

}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

int main() {
	Map Maze;
	Maze.Init();

	Route_Stack<Point> Current;
	Route_Stack<Point> Store;
	Current.Init();
	Store.Init();

	DFS_Search Search;
	Search.Search_Route(&Maze, &Current, &Store);
	Search.Show_Result(&Maze, &Store);


	return 0;
}