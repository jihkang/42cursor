import App from '@/App';
import { ApiContainer } from '@/utils/api';
import axios from 'axios';
import React from 'react';
import ModalProvider from '@/provider/ModalProvider';

const apiContainer = new ApiContainer(axios);

export const ApiContainers = React.createContext<ApiContainer>(apiContainer);

export const ApiProvider = () => {
  return (
    <>
      <ApiContainers.Provider value={apiContainer}>
        <ModalProvider>
          <App />
        </ModalProvider>
      </ApiContainers.Provider>
    </>
  );
};
