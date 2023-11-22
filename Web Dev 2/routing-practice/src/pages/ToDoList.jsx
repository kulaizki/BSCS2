import { useState } from 'react';
import './ToDoList.css';
import Task from '/src/components/Task';
import TaskInput from '/src/components/TaskInput'; 

function ToDoList() {
  const [tasks, setTasks] = useState([]);

  const handleAddTask = (newTask) => {
    setTasks([...tasks, newTask]);
  };

  const handleDeleteTask = (taskToDelete) => {
    const updatedTasks = tasks.filter((task) => task !== taskToDelete);
    setTasks(updatedTasks);
  };

  return (
    <div>
      <h1>Todo List</h1>
      <TaskInput onAddTask={handleAddTask} />
      <div className="task-list">
        {tasks.map((task, index) => (
          <Task key={index} task={task} onDelete={handleDeleteTask} />
        ))}
      </div>
    </div>
  );
}

export default ToDoList;