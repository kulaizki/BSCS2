import { useState } from 'react';
import './App.css';
import Task from './components/Task';
import TaskInput from './components/TaskInput'; 

function App() {
  const [tasks, setTasks] = useState([]);

  const handleAddTask = (newTask) => {
    setTasks([...tasks, newTask]);
  };

  const handleDeleteTask = (taskToDelete) => {
    const updatedTasks = tasks.filter((task) => task !== taskToDelete);
    setTasks(updatedTasks);
  };

  return (
    <div className="App">
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

export default App;