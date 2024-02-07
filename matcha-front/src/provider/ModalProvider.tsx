import Modal, { ModalBody } from '@/components/Modal';
import Login from '@/page/auth/login';
import SearchModal from '@/page/modal/SearchModal';
import LoginModal from '@/page/modal/loginModal';
import { ModalProps } from '@/types';
import { createContext, useEffect, useState } from 'react';

export const ModalContext = createContext({
  modalProp: {
    modalType: 'searchModal',
    toggle: true,
  },
  setModal: (modalProp: any) => {},
});

const ModalProvider: React.FC<ModalProps> = ({ children }) => {
  const [modalProp, setModal] = useState({
    modalType: '',
    toggle: false,
  });
  useEffect(() => {
    console.log('fucking error');
    const onKeyDown = (e: KeyboardEvent) => {
      if (modalProp.modalType === '') {
        if (e.key === 'k' && e.metaKey && modalProp.modalType === '') {
          setModal({
            modalType: 'searchModal',
            toggle: true,
          });
        } else if (e.key === 'k' && e.ctrlKey) {
          setModal({
            modalType: 'loginModal',
            toggle: true,
          });
        }
      } else {
        if (e.key === 'Escape') {
          setModal({
            modalType: '',
            toggle: false,
          });
        }
      }
    };
    window.addEventListener('keydown', onKeyDown);
    return () => {
      window.removeEventListener('keydown', onKeyDown);
    };
  }, []);

  return (
    <>
      <ModalContext.Provider value={{ modalProp, setModal }}>
        {children}
        {modalProp.modalType === 'searchModal' && modalProp.toggle && <SearchModal />}
        {modalProp.modalType === 'loginModal' && <LoginModal />}
      </ModalContext.Provider>
    </>
  );
};

export default ModalProvider;
