import React, { useCallback, useEffect, useState } from 'react';
import debounce from '@/utils/debounce';
import Card, { CardBody } from '@/components/Card';
import Input from '@/components/input';
import Modal, { ModalHeader, ModalBody } from '@/components/Modal';
import Button from '@/components/Button';
import Login from '@/page/login/login';

function App() {
  const [open, setOpen] = useState(false);
  const [text, setText] = useState('');
  const setChangeData = useCallback(
    debounce((data: any) => {
      setText(data);
    }, 400),
    [],
  );

  const onChange = (e: React.FormEvent<HTMLInputElement>) => {
    const {
      currentTarget: { value },
    } = e;
    setChangeData(value);
  };

  useEffect(() => {
    const onKeyDown = (e: KeyboardEvent) => {
      if (e.key === 'k' && e.metaKey) {
        setOpen(true);
      } else if (e.key === 'Escape') {
        setOpen(false);
      }
    };
    window.addEventListener('keydown', onKeyDown);
    return () => {
      window.removeEventListener('keydown', onKeyDown);
    };
  }, []);
  return (
    <>
      {open ? (
        <Modal width={'300px'} onToggle={() => setOpen(false)}>
          <ModalHeader>
            <Input onChange={onChange} />
            <button
              onClick={() => {
                setOpen(!open);
              }}
            >
              close
            </button>
          </ModalHeader>
          <ModalBody>{text}</ModalBody>
        </Modal>
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
      )}
      <Login />
    </>
  );
}

export default App;
