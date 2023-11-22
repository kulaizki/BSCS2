import React, { useState } from 'react';

function EditContact({ contact, editContact, onCancel }) {
  const [editedContact, setEditedContact] = useState(contact);

  const handleInputChange = (e) => {
    const { name, value } = e.target;
    setEditedContact({ ...editedContact, [name]: value });
  };

  const handleSave = () => {
    editContact(editedContact);
    onCancel();
  };

  const handleCancel = () => {
    setEditedContact(contact);
    onCancel();
  };

  return (
    <div className="editContact">
      <h2>Edit Contact</h2>
      <form onSubmit={handleSave}>
        <input
          type="text"
          name="name"
          placeholder="Name"
          value={editedContact.name}
          onChange={handleInputChange}
        />
        <input
          type="number"
          name="age"
          placeholder="Age"
          value={editedContact.age}
          onChange={handleInputChange}
        />
        <input
          type="number"
          name="number"
          placeholder="Contact Number"
          value={editedContact.number}
          onChange={handleInputChange}
        />
        <input
          type="number"
          name="id"
          placeholder="ID #"
          value={editedContact.id}
          onChange={handleInputChange}
        />
        <input
          type="text"
          name="course"
          placeholder="Course"
          value={editedContact.course}
          onChange={handleInputChange}
        />
        <button type="submit">Save Changes</button>
        <button type="submit" onClick={handleCancel}>Cancel</button>
      </form>
    </div>
  );
}

export default EditContact;