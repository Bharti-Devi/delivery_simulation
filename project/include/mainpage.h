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
* \image html "Iteration3UML.png" width=1000in
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
* The DeliverySimulation schedules a delivery. It does this by creating a DeliveryObject from a Package and a Customer in its 
* entities_ list and then picks a DeliveryVehicle (either a Drone or a Robot) to be assigned the delivery. Finally, as the simulation 
* is running it calls Update on every DeliveryVehicle in its entities_ list which makes the DeliveryVehicle use the DeliveryObject to 
* complete the delivery.
* 
* # Iteration 1 #
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
* # Iteration 2 #
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
*
* # Iteration 3 #
*
* ## New Features: ##
* The new feature we decided to implement for the third iteration was the color changing feature. We chose this feature as we thought 
* that it would be fun to have the IEntities change colors especially the customer as they get angrier. In order to implement the 
* feature, we discussed how we would do it, one of the ideas we had was to implement the color changing code directly into the 
* update functions, however that would break the Open-Closed Principle. We eventually decided to use the Decorator pattern due to 
* its advantages over other strategies for implementing a color changer.
*
* \image html "DecoratorUML.png" width=750in
*
* One of these advantages is that it follows the Open-Closed Principle. Other methods of implementing color changing would involve 
* directly changing the update methods of the entity types. The problem with this is that if you wanted multiple different ways an 
* object can change its colors, for example rather then delivery objects changing based on battery charge, have them change color 
* based on distance, you would have to make a new class and that is a clone of the delivery object and change the code of it to do 
* the other thing. Rather then go through this process the decorator pattern allows you to simply make a new decorator class to 
* attach to the already existing delivery object which will deal with the color changing only. Not modifying the already existing 
* code. 
* ### Angry Customer: ###
*	For this first decorator we had it change the color of the customer according to how far away the package is, as the package 
* gets closer the customer gets angry. For the angry customer their were many issues with circular includes, however eventually 
* using forward declares the issue was solved.
* ### Battery Power: ###
* 	For this decorator we had it change the color of the delivery vehicles according to the battery power left in the drone. As 
* the battery drains it switches to yellow then red. There were issues with getting get details and the color to show up on the 
* terminal, however changing the drones GetDetails() the problem was able to be fixed.
* ### Closeness to Delivery: ###
*	For this final decorator we had it change the color from red to green as the package gets closer to the customer. A difficult 
* part of setting up the Package decorator, was dealing with the GetDetails() as forgetting to have the decorator call the 
* packages GetDetails() for its get details causes weird problems for the simulation, so it was difficult to find the mistake and 
* fix it. 
* ## Iteration 3 Team Documentation: ##
* ### Meeting 1: 4/22 ###
* Everyone was present.
* For our first meeting for the third implementation we went over which features we wanted to implement for this last section of 
* the project, and how we would split up the work. What we eventually ended up deciding was that we would implement three different 
* decorators that would allow for the different entities to change colors based on what was going on. The three that we decided to
* implement were the customer would change color as more time passed without having the package to simulate anger, the package 
* changing color as it got closer to the customer, and the battery changing color as the delivery_object’s battery power gets 
* lower. We then discussed later meeting times for the rest of the iteration.
* #### Angry Customer: Viara Milenova #####
* #### Battery Power: Bharti Devi ####
* #### Closeness to Delivery: Oliver Cuzzourt ####
* #### Documentation/GoogleTests: James Eichstaedt ####
* ### Meeting 2: 4/27 ###
* Everyone was present.
* For our second meeting we first went over how everyone was doing for their section of the project and discussed finishing the 
* programming by Thursday night in order to allow time for the documentation to be complete. We also discussed possible changes 
* to older code to allow for easier implementation of the decorator pattern to allow for the changing of colors for the IEntity 
* objects. We decided to implement the change to entity base to move the observer list to be included in its code rather then in 
* its children to allow for better abstraction when dealing with the Decorator pattern. Once we were done discussing 
* implementation three, we went on to discuss our final presentation, choosing and signing up for Tuesday the 4th. We decided
* that we would discuss the presentation further at the next meeting.
* ### Meeting 3: 4/30 ###
* Everyone was present.
* For our third and final meeting for this implementation we went over last checks including the UML and the documentation.
* Firstly we talked about issues with the code and ways to solve them, mainly how to fix the circular issues in the implementation
* of Angry customer. After this we went over our plans for when we would get the presentation done and concluded that we would
* meet up some time on Sunday to work on the presentation together.
*
* ### What to Test On ###
* Please Test on scenes/umn.json and in order to better see the battery depletion causing the color change 
* scenes/drone_low_battery_a.json
*
*/