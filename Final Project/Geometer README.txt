Final Project
Geometer (Alice Yang)
Documentation

Polygon Mesh Load and Write:

	NOTE: You can use the cube_w_mtl.OBJ file in the OBJs folder for testing purposes. The MTL file is example.mtl
	*IMPORTANT* If the program freezes when an OBJ file with an mtl reference is loaded, try putting the folder containing both on
	the desktop. This bug has not happened to me (ie the folder worked anywhere), but one of my group members had problems with this.
	May be because he runs a MAC while I implemented file loading on a PC?

	Loading a mesh is handled by MyLoadButton, and writing an OBJ file is handled by MyExport button.
	When loading an OBJ file that references a .MTL file, the .MTL file MUST BE IN THE SAME DIRECTORY AS THE OBJ FILE.
	
	Implementation:
		When loading a mesh, I read the file line by line, and processed it differently depending on the first word in each
		line. If they were v or f, the program made either a vertex or a face, and pushed it into either a vector of Vertex* or 
		a vector of Face*. When a face is pushed in, I looped through its vertices to create new HalfEdges and set their NEXT,
		FACE, and V values. I also used a map which stored a pair of vertices and the halfEdge between them. When processing a 
		face, I pushed the vertices into the vector in reverse order. After everything has been processed, I iterated through
		the map, found the HalfEdge between the pair of vertices (the key), and set its SYM to the HalfEdge in the value field
		of the map. 
		
		To handle materials, the program opens the .mtl file when it sees "mtllib" in a line. There it reads through the MTL file
		line by line, and creates a new Material pointer for each material listed in the file. The newly created materials are then
		pushed into a map, with their string name as the key and the Material pointer as the value. When the program runs into the
		"usemtl" command, it takes the following word and looks up the corresponding Material pointer. This pointer is then set to
		a tracking pointer called currMaterial. When currMaterial is set, the material is applied to all subsequent faces. However.
		when the program runs into the next "usemtl" command, the currMaterial is changed to the new material (via the map lookup),
		and all subsequent faces then have the new material applied to them.
		
		When exporting a mesh, the program creates a new file, and writes to it. If the original mesh contained a material file, the
		program will write that on the first line. It then loops through the vector of vertices and	writes them to the file. Afterwards
		it instantiates a material tracker and starts looping through the vector of faces. If the face's material is the same as the 
		tracker's, nothing new is added. If not, then the line "usemtl" + whatever the new material is is written to the file, and the
		tracker updated. It then loops through all the halfEdges of each face, finds each corresponding vertex from the vertices vector,
		and prints the value of index+1, since OBJ vertex indices start at 1 rather than 0.
		
		Difficulties:
			No known bugs as of now.

Geometry Editing Operation:
	I implemented deleteFace, where the deleted face will be replace with its centroid and HalfEdges of adjacent face are adjusted. I made it
	so any face with less than 4 edges cannot be deleted in this way.Also if it has incident faces with less than 4 edges it cannot be deleted
	either.
		
Nonplanar/Concave quad splitting
	Implementation:
		I used the planarity check from the last homework and implemented the convexity check in Mesh. When the Mesh is drawn, I loop through
		all the faces and check their planarities and convexities. If either return false, I split them into triangles.
		
Bugs/Difficulties
	Some geometry operations are buggy in corner cases
	

