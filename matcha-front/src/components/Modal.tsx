import { ModalProps } from '@/types';
import { useEffect } from 'react';
import styled from 'styled-components';

const ModalWrapper = styled.div`
  position: fixed;
  display: flex;
  height: 100%;
  width: 100%;
  top: -50%;
  left: -50%;
  transform: translate(50%, 50%);
  justify-content: center;
  align-items: center;
`;

const ModalContainer = styled.div<ModalProps>`
  min-width: 200px;
  min-height: 200px;
  border: 1px solid;
  width: ${(props) => (props?.width ? props.width : 'fit-content')};
  z-index: 100;
`;

export const ModalHeader = styled.div`
  display: flex;
  max-height: 80px;
  width: 100%;
  height: fit-content;
  float: right;
  border-bottom: 1px solid;
  justify-content: space-between;
  gap: 15px;
`;

const ModalOverlay = styled.div`
  position: fixed;
  top: 0;
  width: 100%;
  height: 100%;
  opacity: 0.5;

  background-color: rgba(0, 0, 0, 0.3);
`;

export const ModalBody = styled.div``;

const Modal: React.FC<ModalProps> = (props) => {
  const keyPress = (e: KeyboardEvent) => {
    if (e.key === 'Escape') {
      props.onToggle && props.onToggle();
    }
  };
  useEffect(() => {
    const html = document.documentElement;
    html.style.overflow = 'hidden';
    window.addEventListener('keydown', keyPress);
    return () => {
      html.style.overflow = 'auto';
      window.removeEventListener('keydown', keyPress);
    };
  }, []);
  return (
    <ModalWrapper>
      <ModalOverlay></ModalOverlay>
      <ModalContainer {...props}>{props.children}</ModalContainer>
    </ModalWrapper>
  );
};

export default Modal;
