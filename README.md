# SCC-
Strongly Connected Components <br />
This program incoporates Depth First Search on a file or 
stdin with information of a directed graph. The output will
display each vertex and a list of edges it points to as well
as a table with information about each vertex including
their color, discover time, finish time, and parent vertex.
It will then try and find the Strongly Connected Components
of the graph. It will output the stack it creates as well
as lists of adjacent verticies for the transpose graph.
Lastly it will print out a table as well for the transpose
with the addition of dfstRoots. If the -u command is called
it does everything thinking it's a undirected graph.
If -w is called, it won't find the SCC but rather 
the longest DAG path. It will also print out the 
adjacenecy list with weights.<br />
<br />
To compile, use the command "make" without quotes to start
Makefiles compilation. To run type scc03 [-w] [-u] [inputfile]
where the flag -u creates an undirected graph and -w creates
a weighted graph. Both can be used simultaneously  
