import React, { useState } from "react";
import "./App.css";
import AddContact from "./components/AddContact";
import ContactCard from "./components/ContactCard";
import EditContact from "./components/EditContact";

function App() {
  const [contacts, setContacts] = useState([]);
  const [selectedContact, setSelectedContact] = useState(null);

  const addNewContact = (newContact) => {
    const isDuplicateId = contacts.some(
      (contact) => contact.id === newContact.id
    );

    if (isDuplicateId) {
      alert("ID already exists. Please use a unique ID.");
    } else {
      setContacts([...contacts, newContact]);
    }
  };

  const deleteContact = (contactId) => {
    const updatedContacts = contacts.filter(
      (contact) => contact.id !== contactId
    );
    setContacts(updatedContacts);
  };

  const editContact = (editedContact) => {
    const updatedContacts = contacts.map((contact) =>
      contact.id === editedContact.id ? editedContact : contact
    );
    setContacts(updatedContacts);
    setSelectedContact(null);
  };

  return (
    <>
      <h1>Contact Book</h1>
      <AddContact addContact={addNewContact} />
      <div className="contactList">
        <h2>Contact List</h2>
        <div className="contactCardContainer">
          {contacts.map((contact, index) => (
            <ContactCard
              key={index}
              contact={contact}
              onDelete={deleteContact}
              onEdit={setSelectedContact}
            />
          ))}
        </div>
      </div>
      {selectedContact && (
        <EditContact contact={selectedContact} editContact={editContact} />
      )}
    </>
  );
}

export default App;
