import { useState } from "react";
import { BrowserRouter, Routes, Route, NavLink } from "react-router-dom";
import "./App.css";
import ContactBook from "/src/Pages/ContactBook";
import ToDoList from "/src/Pages/ToDoList";

const navigationLinks = [
  { to: "/", label: "Contact Book" },
  { to: "/todolist", label: "To-Do List" },
];

const App = () => {
  const [loggedIn, setLoggedIn] = useState(false);

  const Protected = ({ isLoggedIn, children }) => (
    <>{isLoggedIn ? children : <h1>No Permission</h1>}</>
  );

  return (
    <BrowserRouter>
    <div className="container">

      <button onClick={() => setLoggedIn(!loggedIn)}>
        {loggedIn ? "Sign Out" : "Sign In"}
      </button>
      <header>
        <nav>
          {navigationLinks.map((link) => (
            <NavLink key={link.to} className="nav-link" to={link.to}>
              {link.label}
            </NavLink>
          ))}
        </nav>
      </header>
      <Routes>
        <Route
          path="/"
          element={
            <Protected isLoggedIn={loggedIn}>
              <ContactBook />
            </Protected>
          }
        />
        <Route
          path="/todolist"
          element={
            <Protected isLoggedIn={loggedIn}>
              <ToDoList />
            </Protected>
          }
        />
      </Routes>
    </div>

    </BrowserRouter>
  );
};

export default App;
