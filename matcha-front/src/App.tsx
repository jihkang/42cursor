import React, { useCallback, useContext, useEffect, useState } from 'react';
import debounce from '@/utils/debounce';
import Card, { CardBody } from '@/components/Card';
import Input from '@/components/input';
import Modal, { ModalHeader, ModalBody } from '@/components/Modal';
import Button from '@/components/Button';
import { ModalContext } from '@/provider/ModalProvider';
import { Outlet } from 'react-router-dom';

function App() {
  return (
    <>
      <Outlet />
      {/* {open ? (
       
      ) : (
        <Button
          onClick={() => {
            setOpen(!open);
            setText('');
          }}
          style={{ display: 'flex', justifyContent: 'space-between', width: 'fit-content' }}
        >
          <div>CMD + K</div>
          <div>Open</div>
        </Button>
      )} */}
      {/* <Login /> */}
    </>
  );
}

export default App;
