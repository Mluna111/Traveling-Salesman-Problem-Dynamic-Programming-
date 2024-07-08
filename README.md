<h1>Traveling Salesman Problem Solver</h1>

<h2>Description</h2>
<p>
    This project implements a solution to the Traveling Salesman Problem (TSP) using dynamic programming. It reads a graph from a file, computes the shortest possible route that visits each city exactly once and returns to the origin city, and outputs the optimal route and its cost.
</p>

<h2>Languages and Utilities Used</h2>
<ul>
    <li><b>C++</b></li>
    <li><b><code>&lt;iostream&gt;</code></b> - For input and output operations.</li>
    <li><b><code>&lt;cmath&gt;</code></b> - For mathematical operations (e.g., square root).</li>
    <li><b><code>&lt;vector&gt;</code></b> - Dynamic array for storing vertices and paths.</li>
    <li><b><code>&quot;graph.h&quot;</code></b> - Header file defining the Graph class for reading and representing the graph data structure.</li>
    <li><b><code>&quot;tspProblem.h&quot;</code></b> - Header file defining the TSP solver class, implementing the dynamic programming solution.</li>
    <li><b><code>&quot;driverTSP.cpp&quot;</code></b> - Main driver program that reads input, initializes the graph, and calls the TSP solver.</li>
</ul>

<h2>Files in the Project</h2>
<ul>
    <li><b><code>&quot;graph.h&quot;</code></b> - Header file containing the Graph class for managing graph data and operations.</li>
    <li><b><code>&quot;tspProblem.h&quot;</code></b> - Header file defining the TSP solver class with methods for solving the TSP problem.</li>
    <li><b><code>&quot;driverTSP.cpp&quot;</code></b> - Main driver program that initializes the graph and calls the TSP solver.</li>
</ul>

<h2>Environments Used</h2>
<ul>
    <li><b>Windows 10</b></li>
</ul>

<h2>How to Run</h2>
<ol>
    <li><b>Compile the Program:</b>
        <pre><code>g++ -o driverTSP driverTSP.cpp</code></pre>
    </li>
    <li><b>Execute the Program:</b>
        <pre><code>./driverTSP</code></pre>
    </li>
    <li>Follow the prompts to enter the filename containing the graph data.</li>
</ol>

<h2>Sample Run</h2>
<p>
    <b>Graph:</b><br>
    1	1	1	0	2	6	3	86	4	64	5	18	6	101<br>
    2	2	1	29	2	0		4	64	5	14	<br>
    3	3	1	62	2	85	3	0	4	98	5	36	6	31<br>
    4	4		2	72	3	23	4	0	5	47	<br>
    5	5	1	16	2	54	3	74	4	68	5	0	6	47<br>
    6	6	1	27	2	98	3	24		5	62	6	0<br>
    <br>
    <b>Output:</b><br>
    Enter file name: v6.txt<br>
    [169, &lt;1,2,5,4,3,6&gt;]

<br/>
<br/>
<p align="center">
<b>Graph file v6.txt: </b>
<br/>
<br/>
<img src="https://imgur.com/MKAfi1j.png" height="80%" width="80%" />
<br />
<br />
<b>Solution: </b>
<br/>
<br/>
<img src="https://imgur.com/fkofVWT.png" height="80%" width="80%" />
<br />
<br />
</p>

<p>
    The program reads the graph data from the file <code>v6.txt</code>, computes the optimal route for the Traveling Salesman Problem, and outputs the minimum cost and the sequence of vertices representing the optimal tour.
</p>
