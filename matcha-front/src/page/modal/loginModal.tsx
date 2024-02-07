import Modal, { ModalBody, ModalHeader } from '@/components/Modal';
import { ModalContext } from '@/provider/ModalProvider';
import { useContext } from 'react';
import Login from '@/page/auth/login';

const LoginModal = () => {
  const value = useContext(ModalContext);
  return (
    <Modal onToggle={() => value.setModal({ modalType: '', toggle: false })}>
      <ModalHeader>
        <h2>Sign in</h2>
      </ModalHeader>
      <ModalBody>
        <Login />
      </ModalBody>
    </Modal>
  );
};

export default LoginModal;
