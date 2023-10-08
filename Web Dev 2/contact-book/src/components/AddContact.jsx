import React, { useState } from 'react';
import './AddContact.css';

function AddContact({ addContact }) {
  const [name, setName] = useState('');
  const [age, setAge] = useState('');
  const [number, setNumber] = useState('');
  const [id, setId] = useState('');
  const [course, setCourse] = useState('');

  const handleSubmit = (e) => {
    e.preventDefault();

    const newContact = {
      name,
      age,
      number,
      id,
      course,
    };

    addContact(newContact);

    setName('');
    setAge('');
    setNumber('');
    setId('');
    setCourse('');
  };

  return (
      <form className='Card' onSubmit={handleSubmit}>
        <input
          type="text"
          placeholder='Name'
          value={name}
          onChange={e => setName(e.target.value)}
        />
        <input
          type="number"
          placeholder='Age'
          value={age}
          onChange={e => setAge(e.target.value)}
        />
        <input
          type="number"
          placeholder='Contact Number'
          value={number}
          onChange={e => setNumber(e.target.value)}
        />
        <input
          type="number"
          placeholder='ID #'
          value={id}
          onChange={e => setId(e.target.value)}
        />
        <input
          type="text"
          placeholder='Course'
          value={course}
          onChange={e => setCourse(e.target.value)}
        />
        <button className='addButton' type='submit'>Add Contact</button>
      </form>
  );
}

export default AddContact;