import Modal, { ModalBody } from '@/components/ui/Modal';
import Login from '@/page/auth/login';
import Register from '@/page/auth/register';
import SearchModal from '@/page/modal/SearchModal';
import LoginModal, { ModalChild } from '@/page/modal/loginModal';
import { ModalProps } from '@/types';
import { createContext, useEffect, useState } from 'react';

export const ModalContext = createContext({
  modalProp: {
    modalType: 'searchModal',
    toggle: true,
  },
  setModal: (modalProp: any) => {},
});

const ModalType: {
  [key: string]: React.ReactNode;
} = {
  loginModal: <Login />,
  signUpModal: <Register />,
};

const ModalProvider: React.FC<ModalProps> = ({ children }) => {
  const [modalProp, setModal] = useState({
    modalType: '',
    toggle: false,
  });
  useEffect(() => {
    const onKeyDown = (e: KeyboardEvent) => {
      if (e.key === 'Escape') {
        setModal({
          modalType: '',
          toggle: false,
        });
        return;
      }
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
        } else if (e.key === 'l' && e.ctrlKey) {
          setModal({
            modalType: 'signUpModal',
            toggle: true,
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
        {modalProp.toggle && (
          <>
            (
            {modalProp.modalType === 'searchModal' ? (
              <SearchModal />
            ) : (
              <ModalChild header={modalProp.modalType} setModal={setModal}>
                {ModalType[modalProp.modalType]}
              </ModalChild>
            )}
            )
          </>
        )}
      </ModalContext.Provider>
    </>
  );
};

export default ModalProvider;
