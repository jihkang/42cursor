import React, { useCallback, useContext, useEffect, useState } from 'react';
import debounce from '@/utils/debounce';
import Card, { CardBody } from '@/components/ui/Card';
import Input from '@/components/ui/input';
import Modal, { ModalHeader, ModalBody } from '@/components/ui/Modal';
import Button from '@/components/ui/Button';
import { ModalContext } from '@/provider/ModalProvider';
import { Outlet } from 'react-router-dom';
import styled from 'styled-components';

const Container = styled.div`
  margin: 0 auto;
  display: flex;
  justify-content: center;
  align-items: center;
`;

function App() {
  return (
    <>
      <Container>
        <Outlet />
      </Container>
    </>
  );
}

export default App;
