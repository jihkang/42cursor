import App from '@/App';
import React from 'react';
import ReactDOM from 'react-dom/client';
import { ApiContainer } from './utils/api';
import axios from 'axios';
import { ApiProvider } from './provider/ApiContainerProvider';

const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);
root.render(
  <React.StrictMode>
    <ApiProvider />
  </React.StrictMode>,
);
