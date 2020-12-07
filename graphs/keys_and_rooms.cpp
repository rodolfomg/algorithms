/*
struct Room {
  string name;
  vector<string> keys;
};

Input:
rooms = [
  { name: "A", keys: ["B", "C"] },
  { name: "B", keys: ["B", "D"] },
  { name: "C", keys: ["A"] },
  { name: "D", keys: ["B", "A"] },
]

Output:
true

key = rooms[0].keys[0]
rooms[key] // Error key is string
*/

class Solution {
public:
  bool canVisitAllRooms(vector<Room>& rooms) {
  	followPath(0, rooms);
  	return visited.count() == rooms.size();
  }

private:
  void followPath(int room, const vector<vector<int>>& rooms) {
  	if (room > rooms.size() || visited[room]) return;

  	visited.set(room);
  	for(auto key : rooms[room]) {
  	  followPath(key, rooms);
  	}
  }

  bitset<1000> visited;
};
