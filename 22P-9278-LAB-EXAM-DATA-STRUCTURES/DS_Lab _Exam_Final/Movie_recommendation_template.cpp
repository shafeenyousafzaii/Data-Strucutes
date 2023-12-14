#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Node
{
public:
	int movieID;
	string title;
	string genre;
	int ratings;
	Node *left;
	Node *right;
	Node(int ID, string t, string g, int r)
	{
		movieID = ID;
		title = t;
		genre = g;
		ratings = r;
		left = NULL;
		right = NULL;
	}
};

class MovieRecommendationSystem
{
public:
	Node *root;

public:
	// define the constructor
	MovieRecommendationSystem()
	{
		root = NULL;
	}
	// Insert a movie into the BST
	void insertMovie(Node *root, int movieID, string title, string genre, int ratings)
	{
		if (root == NULL)
		{
			Node *n = new Node(movieID, title, genre, ratings);
		}
		else if (movieID < root->movieID)
		{
			insertMovie(root->left, movieID, title, genre, ratings);
		}
		else
		{
			insertMovie(root->right, movieID, title, genre, ratings);
		}
	}

	// Recommend movies of a given genre
	void  recommendMoviesByGenre(Node *n, string genre)
	{

		if (n == NULL)
		{
			return;
		}
		recommendMoviesByGenre(n->left, genre);
		if (n->genre == genre)
		{
			cout << n->title << " " << endl;
		}
		recommendMoviesByGenre(n->right, genre);
	}
	bool search(Node *curr, int val)
	{
		if (curr == NULL)
		{
			return false;
		}
		if (curr->movieID == val)
		{
			return true;
		}
		else if (val < curr->movieID)
		{
			return search(curr->left, val);
		}
		else if (val > curr->movieID)
		{
			return search(curr->right, val);
		}
		return false;
	}
	Node *Search(Node *curr, int val)
	{
		if (curr == NULL)
			return NULL;
		if (curr->movieID == val)
		{
			return curr;
		}
		else if (val < curr->movieID)
		{
			return Search(curr->left, val);
		}
		else if (val > curr->movieID)
		{
			return Search(curr->right, val);
		}
		return NULL;
	}
	int getLevel(Node *ptr, Node *n, int level)
	{
		if (ptr == NULL)
			return 0;
		if (ptr == n)
			return level;

		int l = getLevel(ptr->left, n, level + 1);
		int r = getLevel(ptr->right, n, level + 1);

		if (l == 0)
			return r;
		else if (r == 0)
			return l;
		else
			return 0;
		// return l | r;
		// return getLevel(ptr->left, val, level+1) |
		// getLevel(ptr->right, val, level+1);
	}
	Node *parent(Node *curr, Node *p, Node *par)
	{
		if (curr == NULL)
			return NULL;

		if (curr == p)
		{
			return par;
		}
		else
		{
			Node *t = NULL;
			t = parent(curr->left, p, curr);
			if (t != NULL)
				return t;
			else
			{
				t = parent(curr->right, p, curr);
				return t;
			}
		}
	}
	int maxDepth(Node *n)
	{
		if (n == NULL)
			return -1;
		else
		{
			/* compute the depth of each subBST */
			int lDepth = maxDepth(n->left);
			int rDepth = maxDepth(n->right);

			/* use the larger one */
			if (lDepth > rDepth)
				return (lDepth + 1);
			else
				return (rDepth + 1);
		}
	}
	// Delete movie by ID
	Node *deleteMovieByID(Node *curr, int movieID)
	{
		bool y = search(curr, movieID);
		// cout << y << endl;
		// printBST(Root,NULL,false);
		Node *location = Search(curr, movieID);
		if (y == 1)
		{
			// cout << "Enter " << endl;
			if (location->left == NULL && location->right == NULL)
			{
				// cout << location->data << endl;
				// if (location->left == NULL)
				// {
				//     cout << "NULL";
				// }
				// if (location->right == NULL)
				// {
				//     cout << "NULL";
				// }

				// cout << "I AM HERE" << endl;
				Node *p = parent(root, location, NULL);
				// cout << "WORKING" << endl;
				if (p->left == location)
				{
					// cout << "WORKING" << endl;
					p->left = NULL;
					delete location;
					return NULL;
				}
				else if (p->right == location)
				{
					p->right = NULL;
					delete location;
					return NULL;
				}
			}
			if ((location->left == NULL && location->right != NULL))
			{
				int level = 0;
				int depth = 0;
				depth = maxDepth(root);
				level = getLevel(root, location, 0);
				// cout << "DE" << depth << endl;
				// cout << "Level" << level << endl;
				int l = depth - level;
				if (l == 1)
				{
					if (location->right != NULL)
					{
						Node *p = parent(root, location, NULL);
						if (p->left == location)
						{
							p->left = location->right;
							delete location;
						}
						else if (p->right == location)
						{
							p->right = location->right;
							delete location;
						}
					}
				}
				else if (l != 1)
				{

					Node *p = parent(root, location, NULL);
					if (location->movieID == movieID && p == NULL)
					{
						root = location->right;
						delete location;
						return NULL;
					}
					if (p->left == location)
					{
						p->left = location->right;
						delete location;
					}
					else if (p->right == location)
					{
						p->right = location->right;
						delete location;
					}
				}
			}
			else if ((location->right == NULL && location->left != NULL))
			{
				int level = 0;
				int depth = 0;
				depth = maxDepth(root);
				level = getLevel(root, location, 0);
				int l = depth - level;
				if (l == 1)
				{

					if (location->left != NULL)
					{
						Node *p = parent(root, location, NULL);
						if (p->left == location)
						{
							p->left = location->left;
							delete location;
						}
						else if (p->right == location)
						{
							p->right = location->left;
							delete location;
						}
					}
				}
				else if (l != 1)
				{
					Node *p = parent(root, location, NULL);
					if (location->movieID == movieID && p == NULL)
					{
						root = location->left;
						delete location;
						return NULL;
					}
					if (location->left != NULL)
					{

						if (p->left == location)
						{
							p->left = location->left;
							delete location;
						}
						else if (p->right == location)
						{
							p->right = location->left;
							delete location;
						}
					}
				}
			}

			else if (location->left != NULL && location->right != NULL)
			{
				Node *n = find_predessor(location, movieID);
				location->movieID = n->movieID;
				return deleteMovieByID(n, n->movieID);
			}
		}
		else
		{
			cout << "No value found to delete" << endl;
			return NULL;
		}
		return NULL;
	}
	Node *find_predessor(Node *r, int val)
	{
		if (val < r->movieID)
		{
			if (r->left == NULL && r->right == NULL)
			{
				return r;
			}
			else if (r->left == NULL && r->right != NULL)
			{
				return r;
			}
			else if (r->left != NULL && r->right == NULL)
			{
				return r;
			}
			return find_predessor(r->left, val);
		}
		else if (val > r->movieID)
		{

			if (r->left == NULL && r->right == NULL)
			{
				return r;
			}
			else if (r->left == NULL && r->right != NULL)
			{
				return r;
			}
			else if (r->left != NULL && r->right == NULL)
			{
				return r;
			}
			return find_predessor(r->right, val);
		}
		else if (r->movieID == val)
		{
			if (r->left != NULL && r->right != NULL)
			{
				return find_predessor(r->left, val);
			}
			else if (r->left == NULL && r->right == NULL)
			{
				return find_predessor(r->left, val);
			}
			else if (r->left != NULL && r->right == NULL)
			{
				return find_predessor(r->left, val);
			}
			else if (r->left == NULL && r->right != NULL)
			{
				return find_predessor(r->right, val);
			}
			return NULL;
		}
		return NULL;
	}
	// void bubbleSort(string arr[], int size)
	// {
	// 	for (int i = 0; i < (size - 1); i++)
	// 	{
	// 		for (int j = 1; j < (size - i); j++)
	// 		{
	// 			if (arr[j - 1] > arr[j])
	// 				swap(arr[j - 1], arr[j]);
	// 		}
	// 	}
	// }
};
void displayMovies(vector<int> &arr, int size)
{
		for (int i = 0; i < (size - 1); i++)
		{
			for (int j = 1; j < (size - i); j++)
			{
				if (arr[j - 1] > arr[j])
					swap(arr[j - 1], arr[j]);
			}
		}

		for(int i = arr.size()-1 ; i >= 0 ; i--)
		{
			cout<<"Ratings : "<<arr[i] << endl;
		}
}
int main()
{
	MovieRecommendationSystem engine;
	vector<int> arr;
	int choice;
	while (true)
	{
		cout << "Menu:\n";
		cout << "1. Add a Movie\n";
		cout << "2. Delete a Movie by ID\n";
		cout << "3. Recommend Movies by Genre\n";
		cout << "4. Display Movies Sorted by Ratings\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int movieID;
			string title, genre;
			double ratings;
			cout << "Enter Movie ID: ";
			cin >> movieID;
			cin.ignore(); // Clear newline character from the buffer
			cout << "Enter Movie Title: ";
			getline(cin, title);
			cout << "Enter Movie Genre: ";
			getline(cin, genre);
			cout << "Enter Ratings: ";
			cin >> ratings;
			arr.push_back(ratings);
			engine.insertMovie(engine.root, movieID, title, genre, ratings);
			cout << "Movie added successfully!" << endl;
			break;
		}
		case 2:
		{
			int deleteID;
			cout << "Enter Movie ID to delete: ";
			cin >> deleteID;
			engine.root = engine.deleteMovieByID(engine.root, deleteID);
			arr.pop_back();
			cout << "Movie with ID " << deleteID << " deleted successfully!" << endl;
			break;
		}
		case 3:
		{
			string genre;
			cout << "Enter your favorite genre: ";
			cin.ignore(); // Clear newline character from the buffer
			getline(cin, genre);
			cout<<genre<<endl;
			engine.recommendMoviesByGenre(engine.root, genre);
			break;
		}
		case 4:
			if(arr.size()==0)
			{
				cout<<"No movies to show"<<endl;
				break;
			}
			displayMovies(arr,arr.size());
			break;
		case 5:
			cout << "Exiting the program." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}
	return 0;
}
