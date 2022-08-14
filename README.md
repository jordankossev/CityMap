# City Map
A simple project implementing a weighted digraph as a city map

The map information is stored in a text file where each row corresponds to a different junction. The format of the rows is:

  <junction> <neighbour(0)> <distance(0)> <neighbour(1)> <distance(1)> ...
  
 where <distance(i)> is the distance from <junction> to <neighbour(i)>.
  
  ### Commands
    - path <from> <to>                  Checks for the existance of path between two junctions.
    - three-shortest-paths <from> <to>  Prints the three shortest paths between two junctions.
                                        Furthermore, the user would be asked to specify junctions that are closed (if any).
    - cycle <junction>                  Checks if <junction> is part of a cycle.
    - tourist-path                      Checks if there is an Eulerian path in the graph representation of the map. If such path exists it is printed.
    - path-to-all <junction>            Checks whether it's possible to reach all junction from <junction>
    - dead-ends                         Prints all the dead end streets in the city.
