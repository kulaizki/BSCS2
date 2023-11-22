import React, { useState } from "react";
import "./App.css";

function App() {
  const [dogImage, setDogImage] = useState("");

  const fetchDogImage = async () => {
    try {
      const response = await fetch("https://dog.ceo/api/breeds/image/random");
      const data = await response.json();
      setDogImage(data.message);
      console.log(data)
    } catch (error) {
      console.error("Dog image unavailable", error);
    }
  };

  return (
    <div className="container">
      <h1>Dog API</h1>
      <button onClick={fetchDogImage}>
        Click to generate a new dog picture!
      </button>
      {dogImage && <img style={{width:'480px', height:'480px'}} src={dogImage} alt="dog image" />}
    </div>
  );
}

export default App;
