import React from 'react';
import './ContactCard.css'

function ContactCard({ contact, onDelete, onEdit }) {
  const handleDelete = () => {
    onDelete(contact.id);
  };

  const handleEdit = () => {
    onEdit(contact);
  };

  return (
    <div className="ContactCard">
      <p><strong>Name:</strong> {contact.name}</p>
      <p><strong>Age:</strong> {contact.age}</p>
      <p><strong>Contact Number:</strong> {contact.number}</p>
      <p><strong>ID #:</strong> {contact.id}</p>
      <p><strong>Course:</strong> {contact.course}</p>
      <div className="ContactCardButtons">
        <button onClick={handleEdit}>Edit</button>
        <button onClick={handleDelete}>Delete</button>
      </div>
    </div>
  );
}

export default ContactCard;