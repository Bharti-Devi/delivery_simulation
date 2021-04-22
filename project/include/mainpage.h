/*! \mainpage CSCI 3081 Delivery Simulation Project
*
* # How to Run the Simulation #
*
* Pull the files from the master branch of the GitHub repository and it will contain all of the files required to run the 
* simulation. Once the files have been pulled from GitHub navigate to the <I>/project</I> folder in your terminal. This folder's path 
* should look like <I>umn-csci-3081-s21/repo-iter2-<section>-<team>/project</I>.
* Next run the make command using the terminal and the files will compile. Once the files are compiled, to start the simulation 
* run the command: <I>./bin/run.sh</I>. Once the simulation starts open your web browser and go to http://127.0.0.1:8081. 
* The simulation should be running on your web browser from there and may take a few seconds to load all of the assets in. 
* To end the simulation either click the kill simulation button in the top right corner of the web browser or input the command 
* ctrl+c in the terminal.
*
*
* You can also change the simulation scene. The different scene options can be found in your project folder by navigating to
* <I>project/web/iter1</I>_scenes for Iteration 1 options or to <I>project/web/scenes</I> for Iteration 2 options. To use a 
* different scene, run the command: <I>./bin/run.sh <specified-scene>.json</I>. 
* For example, <I>./bin/run.sh drone_and_robot_many_deliveries.json</I>.
* 
* 
* 
* # Program Design #
*
* \image html "Iteration2UML.png" width=1000in
*
* The design of the program starts with the DeliverySimulation class. The Delivery Simulation class runs the simulation by using 
* the other program classes to change values of different objects in the simulation. 
*
* The DeliverySimulation uses different factory classes. DeliverySimulation creates a CompositeFactory object which it then fills with 
* the factories needed for each entity required for the simulation. Those factories are DroneFactory, RobotFactory, PackageFactory, 
* and CustomerFactory. The Composite Factory is given these factories and it stores them in a list inside itself. Then when 
* DeliverySimulation wants to create an entity it calls CompositeFactory to make it. CompositeFactory uses the composite pattern by 
* iterating over its list of other factories and having each of those create a factory before returning the one that is the correct 
* object type. DeliverySimulation then gets this object and stores it in its entities_ list. 
* 
* 
* DeliverySimulation also uses path factories. It creates a CompositePathfinderFactory object which is then filled with factories for 
* the path routes. Those factories are BeelinePathfinderFactory, ParabolicPathfinderFactory, and SmartPathfinderFactory. The 
* PathfinderFactory also has a list of factories in which it stores the different types of PathfinderFactory objects when they are 
* passed into it. After PathfinderFactory iterates its own list, it returns the correct object type. That object is then also stored 
* in the entities_ list of DeliverySimulation.
* 
* 
* DeliverySimulation also stores a manager object which it gets from the SimpleDeliveryManager class. The SimpleDeliveryManager 
* assigns deliveries to DeliveryVehicles in the order they are scheduled. Packages that are dropped are moved to the front of the queue.
* 
*  
* Pathfinder and SimpleDeliveryManager objects need a graph to be implemented. DeliverySimulation sets the graph for all Pathfinder 
* objects through the PathfinderFactory and SimpleDeliveryManager classes using an IGraph object. 
* 
* 
* DeliverySimulation also tracks observers that need to be notified when there is a change to a Package, Drone, or Robot object. 
* Observers are added to the DeliverySimulation's observers_ list and attached to a DeliveryVehicle. Observers can also be removed 
* from the observers_ list in DeliverySimulation.
* 
* 
* The DeliverySimulation does schedules a delivery. It does this by creating a DeliveryObject from a Package and a Customer in its 
* entities_ list and then picks a DeliveryVehicle (either a Drone or a Robot) to be assigned the delivery. Finally, as the simulation 
* is running it calls Update on every DeliveryVehicle in its entities_ list which makes the DeliveryVehicle use the DeliveryObject to 
* complete the delivery.
* 
* 
* 
* # Concrete vs. Abstract vs. Composite Factory Design #
*
* ## Concrete: ##
* 
* A concrete design for factories is a very simple design, having a single factory which uses an if else statement to create the 
* proper object. If we were to use the concrete factory design in the project, it would look like this:
*
* \image html "ConcreteUML.png" width=750in
*
* The concrete factory design is very simple, and it is great in its simplicity. It does not require any manual memory allocation 
* so it is a very safe and easy design to implement for the program, and for such a large project, a safe and easy choice is very 
* tempting as it is less likely to result in segmentation faults or other memory issues. Despite this however the concrete design
* is only good if the number of objects needed to be made rarely changes during development, this is because every time a new 
* object is introduced a new if else statement needs to be added to the factory. Along with this Polymorphism is difficult as it 
* returns the objects as the child class, not the Parent class, so the DroneFactory would return a Drone object, when for this 
* project we want it to return a IEntity object that is a drone.
*
* ## Abstract: ##
*
* An abstract design for factories is harder to implement then the concrete design, but not by much. It consists of multiple 
* factories which inherit from an abstract factory and create their object type, however return it as the parent class allowing 
* for Polymorphism of the returned object. If we were to use the abstract factory design in the project, it would look like this:
*
* \image html "AbstractUML.png" width=750in
*
* The abstract factory design is great as it allows for polymorphism of the objects returned from the factory’s creation. This is 
* important for the objects as polymorphism is such a powerful tool to use and is needed for other parts of the project to work 
* properly. A problem however with the abstract factory design is that it requires multiple factory objects. This means that in 
* order to create different entities an if statement still needs to be made somewhere in the program when creating an entity. 
*
* ## Composite: ##
*
* A composite design for factories is very similar to the abstract design however it has one key difference, the addition of a 
* composite factory. The composite factory still inherits from the abstract factory; however, it has the key difference that it 
* has a list of abstract factories in it. A function adds factories input to the composite factory to it and its create entity 
* calls create entity on all of the factories added to the list and then returns the value that is returned from the correct 
* factory. If we were to use the composite factory design in the project, it would look like this:
*
* \image html "CompositeUML.png" width=750in
*
* The composite design is the best choice for the project as it allows for polymorphism as well as the ability to easily add new
* objects without having to edit other classes to get it all to work together, as there are no if statements. A negative of the 
* composite design is that due to its implementation the rest of the classes will need to perform runtime checks to make sure 
* that it is using the correct kind of object and not resulting in segmentation faults for trying to reference things that are 
* not there.
*
* Our final choice after reviewing these three designs was to use the composite factory design as it works best with what is 
* planned for the project as not only is polymorphism extremely important but we will be adding more object types that inherit 
* from IEntity so having less work to do to add these objects is extremely important.
*
*
* # Designing and Implementing the different routes #
* For designing and implementing the different routes we decided to use the Strategy Design as discussed in chapter 1 of the Head 
* First Design Patterns textbook. We decided to use this design as it implements a simple way to allow even objects of the same 
* type to have different strategies, which is important for the project to work correctly. Along with this the strategy pattern also 
* allows for easier implementation within the object as you do not have to write or rewrite the code for the different path patterns, 
* only once in the concrete strategy object.
* 
* \image html "PathfinderUML.png" width=750in
* 
* As shown in the UML above the pathfinder worked by creating an abstract class which the delivery vehicles have and concrete classes 
* that inherit off of the abstract class so that they can be stored and actually called upon by the delivery vehicle classes. For 
* actually writing the GetPaths for the routes, beeline and smart were easy as smart just used the GetPath of the IGraph, and Beeline 
* you only had to push three points. Parabolic however was much more difficult, however after reviewing the lab and the announcement 
* called “Parabolic Path second approach”, we decided to implement the second approach as it seemed much easier to understand and write.
* 
* 
* After implementing the Pathfinder code, we had to figure out how to get the proper concrete Pathfinder into the DeliveryObjects. To 
* do this we re-implemented the factory pattern that we used to create IEntities, this time however we did it for the Pathfinders. Five
* classes were made for this: an abstract factory, a composite factory, and one factory for each of the paths. The factories have two 
* different functions: CreatePathfinder() which returns a Pathfinder pointer and SetGraph() which returns nothing, but sets the 
* factories' IGraph to the passed in graph. This had to be done as the Smart pathfinder requires an IGraph, and later implementations of 
* Parabolic and Beeline may take into account the height in the IGraph to figure out the most efficient beeline or parabolic path. Once 
* the factories were completed, they were added to DeliverySystem, DroneFactory, and RobotFactory. DeliverySystem holds a pointer to a 
* composite factory which is also stored in the Drone and Robot factories. This allows easier management of SetGraph and makes sure that 
* when Drones and Robots are created, they can call upon the Pathfinder factories to make the proper Pathfinder for the Drone and Robot.
* 
*
* 
* # Teamwork documentation #
* ## Meeting 1 ##
* All team members were present. The goal for this meeting was to assign tasks for the 1st deliverable. We decided to split up priorities 
* 1 and 2 into four tasks, one for each member. 
* 
* 
* ### Task 1: Create a Robot class ###
* This task was assigned to James Eichstaedt.
* 
* 
* ### Task 2: Allow for Multiple Packages to be Delivered ###
* This task was assigned to Oliver Cuzzourt.
* 
* 
* ### Task 3: Observe Packages ###
* This task was assigned to Bharti Devi.
* 
* 
* ### Task 4: Observe Drones and Robots ###
* This task was assigned to Viara Milenova.
* 
* 
* 
* ## Meeting 2 ##
* All team members were present. The goal for this meeting was to assign tasks for the remainder of iteration 2. We separated the tasks by  
* priority 3, priority 4, the Google Tests, and the documentation.
* 
* 
* ### Task 1: Implement a Different Drone Route using the Strategy Pattern ###
* This task was assigned to James Eichstaedt.
* 
* 
* ### Task 2: Drone/Robot Delivery Functionality ###
* This task was assigned to Oliver Cuzzourt.
* 
* 
* ### Task 3: Google Tests ###
* This task was assigned to Bharti Devi.
* 
* 
* ### Task 4: UML and Documentation ###
* This task was assigned to Viara Milenova.
* 
* 
* 
* ## Meeting 3 ##
* All team members were present. The goal for this meeting was to check in where we all were at with our final tasks. We discussed the UML 
* and the Strategy Pattern implementation. We also discussed what everyone was able to accomplish and what would be done by the end of the 
* day. After confirming that we were almost finished with iteration 2 for the final deliverable, we discussed meeting times for beginning to 
* work on iteration 3.
* 
* 
* 
* ## Team Roles ## 
* <B>Development Lead</B>: Oliver Cuzzourt (cuzzo008) 
* 
* <B>Scheduler</B>: Viara Milenova (milen014) 
* 
* <B>Reporter</B>: Bharti Devi (devi0125) 
* 
* <B>Project Manager</B>: James Eichstaedt (eichs029)
*
*
*
* # Observer Pattern Discussion
*
* The observer pattern in our program is functional for packages, drones, and robots.
*
*/