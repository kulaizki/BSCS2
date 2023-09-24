import React, { useState, useEffect } from 'react';
import './Button1.css';

function Button1() {
    const [clicked, setClicked] = useState(false);

    useEffect(() => {
        if (clicked) {
            // After the button is clicked, change the background color to blue
            // and start the fade-out animation
            const timer = setTimeout(() => {
                setClicked(false);
            }, 300); // Adjust the time to match the animation duration

            return () => {
                clearTimeout(timer);
            };
        }
    }, [clicked]);

    const handleClick = () => {
        setClicked(true);
    };

    return (
        <button
            className={`Button1 ${clicked ? 'clicked' : ''}`}
            onClick={handleClick}
        >
            <p>Click</p>
        </button>
    );
}

export default Button1;